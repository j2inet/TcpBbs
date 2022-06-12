#include "TcpSession.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <sstream>
#include <iomanip>
#include <iostream>

TcpSession::TcpSession(int requestSocket, sockaddr_in client_addr)
{
    this->requestSocket = requestSocket;
    this->client_addr = client_addr;

    screen.AddElement(std::make_shared<TextElement>(Dimension{2,2}, Dimension{4,4}));
}


void TcpSession::Run() 
{
    auto rc = pthread_create(&sessionThread, NULL, TcpSession::NewThreadEntryPoint, (void *)this);
}

void TcpSession::Send(std::string msg)
{
    send(requestSocket, msg.c_str(), static_cast<int>(msg.length()) * sizeof(char), 0);
}

void TcpSession::Step()
{
    int bytesAvailable;
    if(bytesAvailable = InputAvailable()>0)
    {        
        std::shared_ptr<char[]> buffer(new char[bytesAvailable], std::default_delete<char[]>());
        int bytesRead = read(requestSocket, buffer.get(), bytesAvailable);

        std::stringstream ss;
        ss << std::hex;
        ss  << std::setbase(16) << std::setw(2) << std::setfill('0');

        
        for(auto i=0;i<bytesRead;++i)
        {
            std::cout <<std::setw(2) << std::setfill('0') <<  static_cast<int>(buffer[i]) << " ";
            ss << std::setw(2) << std::setfill('0') <<  static_cast<int>(buffer[i]) << " ";
        }
        std::cout << std::endl << "________" << std::endl;
        outputBuffer = ss.str();
    }
    usleep(10000);
}

void TcpSession::WriteChanges()
{
    Send(outputBuffer);
    outputBuffer = "";

}

void TcpSession::Render()
{
    auto output = this->screen.Render();
    Send(ANSI::ERASE_SCREEN);
    Send(output);
    
}

void TcpSession::Loop()
{

    while(true) 
    {
        Step();
        WriteChanges();
        Render();
    }
}

int TcpSession::InputAvailable()
{
    return 1;
    int chars_avail;
    int result;
    result = ioctl (requestSocket, FIONREAD, &chars_avail);
    return result;
}

void* TcpSession::NewThreadEntryPoint(void* session)
{
    TcpSession* tcpSession = static_cast<TcpSession*>(session);
    tcpSession->Loop();
    return nullptr;
}