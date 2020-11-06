#include "Client_manager.h"
#include <iostream>
#include <sstream>
#include "../common_src/Socket.h"
#include <sstream>
#include <fstream>

#define TAMANIO_BUFFER 3

void Receptor_input::recibir(){
	Socket socket(-1);
	socket.Connect(ip,port);
	while (!std::cin.eof())
	{
		char buffer[TAMANIO_BUFFER];
		std::cin.read(buffer,TAMANIO_BUFFER);
		std::cout << buffer << std::endl;
		std::cout << std::cin.gcount() << " characters read: " << std::endl;
		socket.Send(buffer,TAMANIO_BUFFER);
	}
	socket.Shutdown(1);
}


Receptor_input::~Receptor_input(){

}
