#include "Receptor_input.h"
#include "Buffer.h"
#include <iostream>
#define TAMANIO_BUFFER 4

void Receptor_input::recibir(){
	//Buffer buf(TAMANIO_BUFFER);
	std::string input_line;
    while(std::cin) {
        std::getline(std::cin, input_line);
        std::cout << input_line << std::endl;
    };
}


Receptor_input::~Receptor_input(){

}
