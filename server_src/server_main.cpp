#include <iostream>
#include "../common_src/Socket.h"
#include "Server_Manager.h"
#include <unistd.h>
#include <thread>
#define CLOSED_FD -1
#define CERRAR_RD_WR 2
#define ERROR 1
#define EXITO 0


int main(int argc,char* argv[]){
	if (argc!=3){
		std::cerr << "Cantidad incorrecta de parametros" << std::endl;
		return ERROR;
	}
	Socket socket(CLOSED_FD);
	socket.Bind_And_Listen(NULL,argv[1]);
	Server_Manager server(std::move(socket));
	server.Guardar_Root(argv[2]);
	server.start();
	std::string user_input;
	while (user_input != "q") {
	    std::cin >> user_input;
	 }
	server.clean();
	server.join();
	return EXITO;
}
