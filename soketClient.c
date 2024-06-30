#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32")

int main(void) {
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        printf("winsock 초기화 실패\n");
        return -1;
    }
    printf("winsock 초기화 성공!!\n");

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        printf("소켓 생성시 문제 발생!!\n");
        WSACleanup();
        return -1;
    }
    printf("소켓 생성 완료!!\n");

    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    if (connect(sock, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        printf("서버에 연결 시도중 문제 발생!!\n");
        closesocket(sock);
        WSACleanup();
        return -1;
    }
    printf("서버에 연결 되었습니다!\n");

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
    char recvBuf[512];

    int recvResult = recv(sock, recvBuf, 512, 0);
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