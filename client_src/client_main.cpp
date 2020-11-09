#include <iostream>
#include <sstream>
#include <string>
#include "Client_manager.h"

int main(int argc, char* argv[]){
	Receptor_input receptor(argv[1],argv[2]);
	receptor.enviar_al_server();
	receptor.recibir_del_server();
	return 0;
}
