#include "TcpServer.h"
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/tcp.h>

using namespace std;
TcpServer::~TcpServer() {
    close(this->listeningSocket);
}

void TcpServer::initialize()
{
    int s = socket(AF_INET,SOCK_STREAM,0);
    int tempArray[1] = {1};

    //setsockopt(s, IPPROTO_TCP, TCP_NODELAY, tempArray, sizeof(int));
    sockaddr socketAddress = {};
    memset(&server_sockaddr, 0, sizeof(server_sockaddr));
    sockaddr_in server_addr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(port);
    cout << "port" << port << endl;
    cout << "address" << address.c_str() << endl;

    inet_pton(AF_INET, address.c_str(), &server_addr.sin_addr);
  
  char buf[INET_ADDRSTRLEN];

    listeningSocket = s;
    int result = ::bind(listeningSocket, (sockaddr *)&server_sockaddr, sizeof(server_sockaddr));
    if (result) {
        std::cerr << "[ERROR] Created socket cannot be binded to ( "
              << inet_ntop(AF_INET, &server_addr.sin_addr, buf, INET_ADDRSTRLEN)
              << ":" << ntohs(server_addr.sin_port) << ")\n";
        isInitialized = false;
        return;
    }
    else 
    {
        std::cout << "[INFO] Sock is binded to ("  
            << inet_ntop(AF_INET, &server_addr.sin_addr, buf, INET_ADDRSTRLEN)
            << ":" << ntohs(server_addr.sin_port) << ")\n";
    }
cout << "result" << result << endl;
isInitialized = true;
}

void TcpServer::AcceptConnections()
{
    cout << "Listening" << endl;;
    if (listen(listeningSocket, SOMAXCONN) < 0) {
        std::cerr << "[ERROR] Socket cannot be switched to listen mode!\n";
        return ;
    }
    sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr); 
    int sock_client; 
    cout << "accept";
    while(true) {
        if ((sock_client = accept(listeningSocket, (sockaddr*)&client_addr, &client_addr_size)) < 0) {
            std::cerr << "[ERROR] Connections cannot be accepted for a reason.\n";
            return ;
        } else {
            HandleRequest(sock_client, client_addr);
        }
    }
}


void TcpServer::HandleRequest(int requestSocket, sockaddr_in client_addr)
{
char host[NI_MAXHOST];
char svc[NI_MAXSERV];
socklen_t client_addr_size = sizeof(client_addr);
char buf[INET_ADDRSTRLEN];

  if (getnameinfo(
        (sockaddr*)&client_addr, client_addr_size,
        host, NI_MAXHOST,
        svc, NI_MAXSERV, 0) != 0) {
    std::cout << "[INFO] Client: (" << inet_ntop(AF_INET, &client_addr.sin_addr, buf, INET_ADDRSTRLEN)
              << ":" << ntohs(client_addr.sin_port) << ")\n"; 
  } else {
    std::cout << "[INFO] Client: (host: " << host << ", service: " << svc << ")\n";
    auto newSession = std::make_shared<TcpSession>(requestSocket, client_addr);
    sessionList.push_back(newSession);
    newSession->Run();
  }
}