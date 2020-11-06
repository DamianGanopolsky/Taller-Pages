#include <iostream>
#include "../common_src/Socket.h"
#include "Server_Manager.h"


int main(int argc,char* argv[]){

	Server_Manager server;
	server.Guardar_Root(argv[2]);
	server.Receive_connections(argv[1]);
	server.Response();


/*	Socket socket(-1);
	socket.Bind_And_Listen(NULL,argv[1]);
	Socket peer=socket.Accept();
	size_t recibidos=1;
	//std::string buf;
	char buff[64];
	while(recibidos!=0){
		recibidos=peer.Receive(buff,64);
		std::cout << buff << std::endl;
	//	fwrite(buf,1,recibidos,stdout);
	}*/
	return 0;
}
