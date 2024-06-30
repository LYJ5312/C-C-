#define HAVE_STRUCT_TIMESPEC
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#include <string.h>
#include <process.h> // for _beginthreadex
#pragma comment(lib, "ws2_32")

#define BUFFER_SIZE 1024

struct ThreadArgs {
    SOCKET sock;
};

void ReceiveMessages(void* args) {
    struct ThreadArgs* threadArgs = (struct ThreadArgs*)args;
    SOCKET sock = threadArgs->sock;
    char message[BUFFER_SIZE];
    int nRcv;

    while (1) {
        nRcv = recv(sock, message, BUFFER_SIZE - 1, 0);
        if (nRcv == SOCKET_ERROR) {
            printf("���� ����..\n");
            break;
        }
        if (nRcv == 0) {
            printf("���� ���� ����\n");
            break;
        }
        message[nRcv] = '\0';
        printf("���� �޼���:%s\n", message);
        message[strcspn(message, "\n")] = 0;  // ���� ���� ����

    }

    closesocket(sock);
    _endthreadex(0);
}

int main(void) {
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        printf("winsock �ʱ�ȭ ����\n");
        return -1;
    }
    printf("winsock �ʱ�ȭ ����!!\n");

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        printf("���� ������ ���� �߻�!!\n");
        WSACleanup();
        return -1;
    }
    printf("���� ���� �Ϸ�!!\n");

    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    if (connect(sock, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        printf("������ ���� �õ��� ���� �߻�!!\n");
        closesocket(sock);
        WSACleanup();
        return -1;
    }
    printf("������ ���� �Ǿ����ϴ�!\n");

    // ������ �ޱ� �� �����⸦ ����ϴ� ������ ����
    struct ThreadArgs args;
    args.sock = sock;
    _beginthread(ReceiveMessages, 0, (void*)&args);


    // ������ ������ (send)
    char message[BUFFER_SIZE];
    while (1) {
        fgets(message, BUFFER_SIZE, stdin);
        message[strcspn(message, "\n")] = 0;  // ���� ���� ����

        if (send(sock, message, (int)strlen(message), 0) == SOCKET_ERROR) {
            printf("���� ����..\n");
            break;
        }

        if (strcmp(message, "exit") == 0) break;


    }

    closesocket(sock);
    WSACleanup();
    return 0;
}
