#include <iostream>
#include <sstream>      // std::stringbuf
#include <string>

#include "Client_manager.h"

int main(int argc, char* argv[]){

	Receptor_input receptor(argv[1],argv[2]);
	receptor.recibir();
	return 0;
}
