#include "Client_manager.h"

#include <iostream>
#include <sstream>
#include "../common_src/Socket.h"
#include <sstream>
#include <fstream>

#define TAMANIO_BUFFER 5

void Receptor_input::recibir(){
	Socket socket(-1);
	socket.Connect(ip,port);
	while (!std::cin.eof())
	{
		char buffer[5];
		std::cin.read(buffer,5);
		std::cout << buffer << std::endl;
		socket.Send(buffer,5);

	}
}


Receptor_input::~Receptor_input(){

}
