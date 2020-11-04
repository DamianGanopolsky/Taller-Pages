#include <iostream>
#include "Receptor_input.h"

int main(int argc, char* argv[]){
	Receptor_input receptor(argv[1],argv[2]);
	receptor.recibir();
	return 0;
}
