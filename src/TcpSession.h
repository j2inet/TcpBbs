#pragma once

#include <vector>
#include <memory>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "Ansi.h"
#include "Screen.h"


class TcpServer;


class TcpSession 
{
public:
    TcpSession(int requestSocket, sockaddr_in client_addr);

    void Run();
    void Send(std::string msg);

private:
    static void* NewThreadEntryPoint(void* TcpSession);
    void Loop();
    int InputAvailable();
protected:
    Screen screen;
    std::string outputBuffer;
    virtual void Step();
    virtual void WriteChanges();
    void Render();

    friend TcpServer;
private:
    int requestSocket;
    sockaddr_in client_addr;
    pthread_t sessionThread;
};