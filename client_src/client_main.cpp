#include "Client_manager.h"

int main(int argc, char* argv[]){
	Client_Manager client(argv[1],argv[2]);
	client.enviar_al_server();
	client.recibir_del_server();
	return 0;
}
