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
#include "TcpSession.h"
#include "Ansi.h"


const std::string ALL_ADAPTERS("0.0.0.0");
const int DEFAULT_PORT = 8888;


class TcpServer {
    int port;
    std::string address;
    int listeningSocket;
    struct sockaddr_in server_sockaddr;
    bool isInitialized = false;

    std::vector<std::shared_ptr<TcpSession>> sessionList;

    public:
        TcpServer(std::string address, int port) {
            this->port = port;
            this->address = address;
            initialize();
        }
        TcpServer(int port):TcpServer(ALL_ADAPTERS, port) { }
        TcpServer():TcpServer(ALL_ADAPTERS, DEFAULT_PORT) {}
        ~TcpServer();

        void AcceptConnections();
        void HandleRequest(int requestSocket, sockaddr_in client_addr);
        bool IsInitialized() { return isInitialized; }
        
    protected:
        void initialize();
};
