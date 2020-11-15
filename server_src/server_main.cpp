#include <iostream>
#include "../common_src/Socket.h"
#include "Server_Manager.h"
#define ERROR 1
#define EXITO 0


int main(int argc,char* argv[]){
	if (argc!=3){
		std::cerr << "Cantidad incorrecta de parametros" << std::endl;
		return ERROR;
	}
	Server_Manager server(argv[1]);
	server.Guardar_Root(argv[2]);
	server();
	std::string user_input;
	while (user_input != "q") {
	    std::cin >> user_input;
	 }
	server.stop_running();
	server.join();
	return EXITO;
}
