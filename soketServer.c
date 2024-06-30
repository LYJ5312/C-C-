#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32")

int main(void) {

    WSADATA wsadata;

    // �ʱ�ȭ ���� 0, ���� -1
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        printf("winsock �ʱ�ȭ ����\n");
        return -1;
    }

    printf("winsock �ʱ�ȭ ����!!\n");

    // 3. ���� ������ �ݱ�.
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == SOCKET_ERROR) {
        printf("���� ������ ���� �߻�!!\n");
        return -1;
    }

    printf("���� ���� �Ϸ�!!\n");


    // 4. �ּҿ� ��Ʈ��ȣ ����
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999); // 9000���� ���ķδ� �� �������. 9000 ~ 63000
    addr.sin_addr.S_un.S_addr = ADDR_ANY;

    // 5. ���ε�
    if (bind(sock, (SOCKADDR_IN*)&addr, sizeof(addr)) != 0) {
        printf("���ε� �� ����!!\n");
        return -1;
    }

    //6. ������(listen) - listen()
    printf("���ε� ����!!\n");
    listen(sock, 5);
    printf("���� ���\n");

    // 7. ���� ���� - accept()
    SOCKADDR_IN caddr;
    SOCKET csock;
    int csize = sizeof(caddr);

    csock = accept(sock, (SOCKADDR_IN*)&caddr, &csize);

    if (csock == SOCKET_ERROR) {
        printf("���� ������ ���� �߻�!!\n");
    }

    printf("���� ����!!\n");
    printf("����� ���� ��ȣ : %d \n", csock);

    // ������ ������ (send)
    const char* message = "Hello, Server!";
    int sendResult = send(sock, message, (int)strlen(message), 0);
    if (sendResult == SOCKET_ERROR) {
        printf("send ����: %d\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
        return -1;
    }
    printf("�޽����� ���½��ϴ�: %s\n", message);
    //�����͹ޱ�
    char recvBuf[513];

    int recvResult = recv(sock, recvBuf, sizeof(recvBuf) - 1, 0);
    if (recvResult > 0) {
        printf("Bytes received: %d\n", recvResult);
    }
    else if (recvResult == 0) {
        printf("Connection closed\n");
    }
    else {
        printf("recv failed: %d\n", WSAGetLastError());
    }

    // cleanup
    closesocket(sock);
    WSACleanup();

    return 0;
}