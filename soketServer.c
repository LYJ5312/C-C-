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

// �������� ����� �迭 �� �ε��� ����
SOCKET clntSocks[MAX_CLIENTS] = { 0 };
int clientCount = 0;

void SendToAllClients(const char* message, int senderIndex) {
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clntSocks[i] != INVALID_SOCKET && i != senderIndex) {
            if (send(clntSocks[i], message, strlen(message), 0) == SOCKET_ERROR) {
                printf("���� ����..\n");
                // ���� ó���� �߰��� �� ����
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
            printf("���� ����..\n");
            break;
        }
        if (nRcv == 0) {
            printf("Ŭ���̾�Ʈ ���� ����\n");
            break;
        }
        message[nRcv] = '\0';
        printf("���� �޽��� : %s\n", message);
        message[strcspn(message, "\n")] = 0;  // ���� ���� ����

        // ��� Ŭ���̾�Ʈ���� ���� �޽��� ����
        SendToAllClients(message, clientIndex);

        if (strcmp(message, "exit") == 0) break;
    }

    closesocket(clntSock);
    clntSocks[clientIndex] = INVALID_SOCKET;  // Ŭ���̾�Ʈ ������ ��ȿȭ
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
    addr.sin_addr.S_un.S_addr = INADDR_ANY;

    if (bind(sock, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
        printf("���ε� �� ����!!\n");
        closesocket(sock);
        WSACleanup();
        return -1;
    }
    printf("���ε� ����!!\n");

    if (listen(sock, MAX_CLIENTS) == SOCKET_ERROR) {
        printf("���� ��� �� ���� �߻�!!\n");
        closesocket(sock);
        WSACleanup();
        return -1;
    }
    printf("���� ��� ��...\n");

    SOCKADDR_IN caddr;
    int csize = sizeof(caddr);
    HANDLE hThreads[MAX_CLIENTS] = { 0 };

    while (clientCount < MAX_CLIENTS) {
        SOCKET clntSock = accept(sock, (SOCKADDR*)&caddr, &csize);
        if (clntSock == INVALID_SOCKET) {
            printf("���� ���� �� ���� �߻�!!\n");
            closesocket(sock);
            WSACleanup();
            return -1;
        }
        printf("Ŭ���̾�Ʈ %d ���� ����!!\n", clientCount + 1);

        // Ŭ���̾�Ʈ�� ����� ����ϴ� ������ ����
        struct ThreadArgs* args = (struct ThreadArgs*)malloc(sizeof(struct ThreadArgs));
        args->clntSock = clntSock;
        clntSocks[clientCount] = clntSock;
        hThreads[clientCount] = (HANDLE)_beginthread(HandleClient, 0, (void*)args);

        clientCount++;
    }

    // ��� Ŭ���̾�Ʈ�� �����尡 ����� ������ ���
    WaitForMultipleObjects(MAX_CLIENTS, hThreads, TRUE, INFINITE);

    // ������� ���� ����
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (hThreads[i] != 0) CloseHandle(hThreads[i]);
        if (clntSocks[i] != INVALID_SOCKET) closesocket(clntSocks[i]);
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}
