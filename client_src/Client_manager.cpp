#include "Client_manager.h"
#include <iostream>
#include <sstream>
#include "../common_src/Socket.h"
#include <sstream>
#include <cstring>
#include <fstream>

#define TAMANIO_BUFFER 64

void Receptor_input::recibir(){
	Socket socket(-1);
	socket.Connect(ip,port);
	while (!std::cin.eof())
	{
		char buffer[TAMANIO_BUFFER];
		std::cin.read(buffer,TAMANIO_BUFFER);
		//std::cout << buffer << std::endl;
		//std::cout << std::cin.gcount() << " characters read: " << std::endl;
		socket.Send(buffer,TAMANIO_BUFFER);
	}
	socket.Shutdown(1);

	ssize_t recibidos=1;
	std::string output;
	char buff[TAMANIO_BUFFER];
	while(recibidos!=0){
		recibidos=socket.Receive(buff,TAMANIO_BUFFER);
		output.append(buff,recibidos);
		memset(buff,0,sizeof(buff));
	}
	std::cout << output << std::endl;

}


Receptor_input::~Receptor_input(){

}