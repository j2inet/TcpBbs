#include <iostream>
#include <memory>
#include "TcpServer.h"

using namespace std;

int main(int argc, char** argv) {

	shared_ptr<TcpServer> server = make_shared<TcpServer>();
	cout << "preaccept" << endl;
	if(server->IsInitialized())
	{
		server->AcceptConnections();
		return 0;
	}
	return -1;
}
