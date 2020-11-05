#include "Receptor_input.h"
//#include "Buffer.h"
#include <iostream>
#include "../common_src/Socket.h"
#include <sstream>
#include "../common_src/Buffer.h"
#define TAMANIO_BUFFER 5

void Receptor_input::recibir(){
	Buffer buf(TAMANIO_BUFFER);
	//std::stringbuf buffer;
	std::string input_line;
	Socket socket(-1);
	socket.Connect(ip,port);
    while(std::cin) {
        std::getline(std::cin, input_line);
        std::cout << input_line << std::endl;
        socket.Send(&input_line[0],input_line.length());
    };
}


Receptor_input::~Receptor_input(){

}
