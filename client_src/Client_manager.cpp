#include "Client_manager.h"
#include <iostream>
#include <sstream>
#include "../common_src/Socket.h"
#include <sstream>
#include <cstring>
#include <fstream>
#include <string>
#define TAMANIO_BUFFER 64

void Client_Manager::enviar_al_server(){
	socket.Connect(ip,port);
	while (!std::cin.eof()){
		char buffer[TAMANIO_BUFFER];
		std::cin.read(buffer,TAMANIO_BUFFER);
		socket.Send(buffer,std::cin.gcount());
	}
	socket.Shutdown(1);

}


void Client_Manager::recibir_del_server(){
	ssize_t recibidos=1;
	std::string output;
	char buff[TAMANIO_BUFFER];
	while (recibidos!=0){
		recibidos=socket.Receive(buff,TAMANIO_BUFFER);
		output.append(buff,recibidos);
		memset(buff,0,sizeof(buff));
	}
	std::string output_sin_newline=output.substr(0, output.size()-1);
	std::cout << output_sin_newline << std::endl;
}

Client_Manager::~Client_Manager(){
}
