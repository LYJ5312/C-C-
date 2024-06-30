#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32")

int main(void) {

    WSADATA wsadata;

    // 초기화 성공 0, 실패 -1
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        printf("winsock 초기화 실패\n");
        return -1;
    }

    printf("winsock 초기화 성공!!\n");

    // 3. 소켓 생성과 닫기.
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == SOCKET_ERROR) {
        printf("소켓 생성시 문제 발생!!\n");
        return -1;
    }

    printf("소켓 생성 완료!!\n");


    // 4. 주소와 포트번호 설정
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999); // 9000번대 이후로는 다 비어있음. 9000 ~ 63000
    addr.sin_addr.S_un.S_addr = ADDR_ANY;

    // 5. 바인딩
    if (bind(sock, (SOCKADDR_IN*)&addr, sizeof(addr)) != 0) {
        printf("바인딩 중 에러!!\n");
        return -1;
    }

    //6. 연결대기(listen) - listen()
    printf("바인딩 성공!!\n");
    listen(sock, 5);
    printf("연결 대기\n");

    // 7. 연결 수립 - accept()
    SOCKADDR_IN caddr;
    SOCKET csock;
    int csize = sizeof(caddr);

    csock = accept(sock, (SOCKADDR_IN*)&caddr, &csize);

    if (csock == SOCKET_ERROR) {
        printf("연결 수립중 에러 발생!!\n");
    }

    printf("연결 성공!!\n");
    printf("연결된 소켓 번호 : %d \n", csock);

    // 데이터 보내기 (send)
    const char* message = "Hello, Server!";
    int sendResult = send(sock, message, (int)strlen(message), 0);
    if (sendResult == SOCKET_ERROR) {
        printf("send 실패: %d\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
        return -1;
    }
    printf("메시지를 보냈습니다: %s\n", message);
    //데이터받기
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