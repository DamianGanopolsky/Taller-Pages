#include <iostream>
#include <sstream>      // std::stringbuf
#include <string>

#include "Client_manager.h"

int main(int argc, char* argv[]){
     // empty stringbuf
/*	std::stringbuf Buffer;
	std::ostream os (&Buffer);
	std::string line;
	while (std::getline(std::cin, line)){

		const char * c = line.c_str();

	    Buffer.sputn(c,5);
	    std::cout << Buffer.str() << std::endl;
	} */
	Receptor_input receptor(argv[1],argv[2]);
	receptor.recibir();
	return 0;
}
