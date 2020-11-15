#include "Client_manager.h"
#include "../common_src/Socket.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#define TAMANIO_BUFFER 64
#define SHUT_WR 1

void Client_Manager::enviar_al_server(){
	socket.Connect(ip,port);
	while (!std::cin.eof()){
		char buffer[TAMANIO_BUFFER];
		std::cin.read(buffer,TAMANIO_BUFFER);
		socket.Send(buffer,std::cin.gcount());
	}
	socket.Shutdown(SHUT_WR);
}


void Client_Manager::recibir_del_server(){
	ssize_t recibidos=1;
	std::string output;
	char buff[TAMANIO_BUFFER];
	while (recibidos!=0){
		recibidos=socket.Receive(buff,TAMANIO_BUFFER);
		fwrite(buff,1,recibidos,stdout);
		memset(buff,0,sizeof(buff));
	}
}

Client_Manager::~Client_Manager(){
}
