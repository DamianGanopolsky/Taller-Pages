#include <iostream>
#include "../common_src/Socket.h"
#include "Server_Manager.h"
#include <unistd.h>
#include <thread>
#define CLOSED_FD -1
#define CERRAR_RD_WR 2


int main(int argc,char* argv[]){
	Socket socket(CLOSED_FD);
	socket.Bind_And_Listen(NULL,argv[1]);
	Server_Manager server(socket);
	server.Guardar_Root(argv[2]);
	server.start();
	//sleep(30);
	std::string user_input = "";
	while (user_input != "q") {
	    std::cin >> user_input;
	 }
	socket.Shutdown(CERRAR_RD_WR);
	socket.Close();
	socket.setToInvalidFd();
	server.join();
	return 0;
}
