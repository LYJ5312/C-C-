#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define HAVE_STRUCT_TIMESPEC
#include <stdio.h>
#include <winsock2.h>
#include <string.h>
#include <process.h> // for _beginthreadex
#pragma comment(lib, "ws2_32")

#define MAX_CLIENTS 2
#define BUFFER_SIZE 1024

struct ThreadArgs {
    SOCKET clntSock;
};

// 전역으로 선언된 배열 및 인덱스 변수
SOCKET clntSocks[MAX_CLIENTS] = { 0 };
int clientCount = 0;

void SendToAllClients(const char* message, int senderIndex) {
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clntSocks[i] != INVALID_SOCKET && i != senderIndex) {
            if (send(clntSocks[i], message, strlen(message), 0) == SOCKET_ERROR) {
                printf("전송 에러..\n");
                // 에러 처리를 추가할 수 있음
            }
        }
    }
}

void HandleClient(void* args) {
    struct ThreadArgs* threadArgs = (struct ThreadArgs*)args;
    SOCKET clntSock = threadArgs->clntSock;
    char message[BUFFER_SIZE];
    int nRcv;

    int clientIndex = -1;
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clntSocks[i] == clntSock) {
            clientIndex = i;
            break;
        }
    }

    while (1) {
        nRcv = recv(clntSock, message, BUFFER_SIZE - 1, 0);
        if (nRcv == SOCKET_ERROR) {
            printf("수신 에러..\n");
            break;
        }
        if (nRcv == 0) {
            printf("클라이언트 연결 종료\n");
            break;
        }
        message[nRcv] = '\0';
        printf("받은 메시지 : %s\n", message);
        message[strcspn(message, "\n")] = 0;  // 개행 문자 제거

        // 모든 클라이언트에게 받은 메시지 전송
        SendToAllClients(message, clientIndex);

        if (strcmp(message, "exit") == 0) break;
    }

    closesocket(clntSock);
    clntSocks[clientIndex] = INVALID_SOCKET;  // 클라이언트 소켓을 무효화
    _endthreadex(0);
}

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
    addr.sin_addr.S_un.S_addr = INADDR_ANY;

    if (bind(sock, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
        printf("바인딩 중 에러!!\n");
        closesocket(sock);
        WSACleanup();
        return -1;
    }
    printf("바인딩 성공!!\n");

    if (listen(sock, MAX_CLIENTS) == SOCKET_ERROR) {
        printf("연결 대기 중 에러 발생!!\n");
        closesocket(sock);
        WSACleanup();
        return -1;
    }
    printf("연결 대기 중...\n");

    SOCKADDR_IN caddr;
    int csize = sizeof(caddr);
    HANDLE hThreads[MAX_CLIENTS] = { 0 };

    while (clientCount < MAX_CLIENTS) {
        SOCKET clntSock = accept(sock, (SOCKADDR*)&caddr, &csize);
        if (clntSock == INVALID_SOCKET) {
            printf("연결 수립 중 에러 발생!!\n");
            closesocket(sock);
            WSACleanup();
            return -1;
        }
        printf("클라이언트 %d 연결 성공!!\n", clientCount + 1);

        // 클라이언트와 통신을 담당하는 스레드 생성
        struct ThreadArgs* args = (struct ThreadArgs*)malloc(sizeof(struct ThreadArgs));
        args->clntSock = clntSock;
        clntSocks[clientCount] = clntSock;
        hThreads[clientCount] = (HANDLE)_beginthread(HandleClient, 0, (void*)args);

        clientCount++;
    }

    // 모든 클라이언트의 스레드가 종료될 때까지 대기
    WaitForMultipleObjects(MAX_CLIENTS, hThreads, TRUE, INFINITE);

    // 스레드와 소켓 정리
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (hThreads[i] != 0) CloseHandle(hThreads[i]);
        if (clntSocks[i] != INVALID_SOCKET) closesocket(clntSocks[i]);
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}
