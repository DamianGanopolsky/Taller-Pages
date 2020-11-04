#include "Receptor_input.h"
#include <iostream>

void Receptor_input::recibir(){
	std::string input_line;
    while(std::cin) {
        std::getline(std::cin, input_line);
        std::cout << input_line << std::endl;
    };
}


Receptor_input::~Receptor_input(){

}
