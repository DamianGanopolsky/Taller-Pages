#include <iostream>
#include "../common_src/Socket.h"
#include "Server_Manager.h"


int main(int argc,char* argv[]){

	Server_Manager server(argv[1]);
	server.Guardar_Root(argv[2]);
	//server.Receive_connections(argv[1]);
	server.start();
	//std::string usr_input = "";
	//while (usr_input != "q") {
	  //  std::cin >> usr_input;
	 //}
	server.join();
	//server.force_stop();

	return 0;
}
