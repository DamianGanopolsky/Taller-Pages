#include <iostream>
#include "../common_src/Socket.h"
#include "Server_Manager.h"


int main(int argc,char* argv[]){

	Server_Manager server;
	server.Guardar_Root(argv[2]);
	server.Receive_connections(argv[1]);
//	server.Response();

	return 0;
}
