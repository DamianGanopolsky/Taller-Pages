#include <iostream>
#include "../common_src/Socket.h"
#include "Server_Manager.h"


int main(int argc,char* argv[]){

	Socket socket(-1);
	socket.Bind_And_Listen(NULL,argv[1]);

	Server_Manager server(socket);
	server.Guardar_Root(argv[2]);
	//server.Receive_connections(argv[1]);
	server.start();
	std::string usr_input = "";
	while (usr_input != "q") {
	    std::cin >> usr_input;
	 }
	std::cout << "HOLA" << std::endl;
	server.Stop_Looping();
	//socket.Close();
	//server.join();

	//server.force_stop();

	return 0;
}
