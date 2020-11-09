#include <iostream>
#include "../common_src/Socket.h"
#include "../common_src/Socket_exception.h"
#include "Server_Manager.h"
#include "ThClient.h"
#include <unistd.h>
#include <thread>
#include <unordered_map>
#define CLOSED_FD -1
#define CERRAR_RD_WR 2


int main(int argc,char* argv[]){
/*	Socket socket(CLOSED_FD);
	socket.Bind_And_Listen(NULL,argv[1]);
	Server_Manager server(socket);
	server.Guardar_Root(argv[2]);
	server.start();
	std::string user_input = "";
	while (user_input != "q") {
	    std::cin >> user_input;
	 }
	socket.Shutdown(CERRAR_RD_WR);
	socket.Close();
	socket.setToInvalidFd();
	server.join();
	return 0; */
		Socket socket(CLOSED_FD);
		socket.Bind_And_Listen(NULL,argv[1]);
		//Server_Manager server(socket);
		//server.Guardar_Root(argv[2]);
		std::unordered_map<std::string, std::string> hash_recursos;



		Socket peer(-1);
		peer=socket.Accept();

		ThClient* client= new ThClient(std::move(peer),hash_recursos);
		client->start();
		client->stop_ex();
		client->join();
		delete client;

}
