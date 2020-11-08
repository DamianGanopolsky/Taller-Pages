#include <iostream>
#include "../common_src/Socket.h"
#include "Server_Manager.h"
#include <unistd.h>
#include <thread>


int main(int argc,char* argv[]){
	Socket socket(-1);
	socket.Bind_And_Listen(NULL,argv[1]);
	Server_Manager server(socket);
	server.Guardar_Root(argv[2]);
	server.start();
	//sleep(30);
	std::string usr_input = "";
	while (usr_input != "q") {
	    std::cin >> usr_input;
	 }
	//socket.Close();
	std::cout << "HOLA" << std::endl;
	server.Stop_Looping();
	std::cout << "ad4" << std::endl;
	//server.join();
	std::cout << "ad5" << std::endl;
	return 0;
}
