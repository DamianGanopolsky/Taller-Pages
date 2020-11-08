#include "Server_Manager.h"
#include "../common_src/File.h"
#include "../common_src/Socket.h"
#include "Parser.h"
#include "Otro_Comando.h"
#include "Comando_Post.h"
#include "Comando_Get.h"
#include "Comando.h"
#include <cstring>
#include <tuple>
#include <sstream>
#include <vector>
#include "../common_src/Socket_exception.h"
#define TAMANIO_BUFFER 64
#define CLOSED_FD -1



void Server_Manager::Guardar_Root(std::string FileName){
	File archivo(FileName);
	int longitud_archivo=archivo.longitud_archivo();
	std::string cuerpo;
	cuerpo.reserve(longitud_archivo);
	archivo.Asign(cuerpo);
	hash_recursos["/"]=cuerpo;
}


void Server_Manager::run(){
//	Socket socket(CLOSED_FD);
	//socket.Bind_And_Listen(NULL,port_to_listen);

	//Socket peer=socket.Accept();
	//ThClient* client= new ThClient(std::move(peer),hash_recursos);
	//client->run();
	//std::vector<ThClient*> clients;
	Socket peer(-1);
	//std::cout << "ACA" << std::endl;
	while(true){
		try{
			std::cout << "paso" << std::endl;
			peer=socket.Accept();
		}
		catch(SocketException &except_msg){
			throw except_msg;
		}
		cant_clientes++;
	//	clients.reserve(2);
		ThClient* client= new ThClient(std::move(peer),hash_recursos);
		clients.push_back(client);
		client->start();
		//std::cout << "asd3" << std::endl;
		//if(total_clients==1){
			//break;
		//}

			//if(total_clients==2){
				//break;
			//}
		}

}

void Server_Manager::Stop_Looping(){
	keep_looping=false;

	for(int i=0;i<cant_clientes;i++){
		clients[i]->stop_ex();
		//std::cout << "poasaa aca" << std::endl;
		clients[i]->join();
		delete clients[i];
	}
	std::cout << "ad1"<< std::endl;
	socket.Shutdown(2);
	std::cout << "ad2"<< std::endl;
	socket.Close();
	std::cout << "ad3"<< std::endl;
}


Server_Manager::~Server_Manager(){
	keep_looping=false;
	for(int i=0;i<cant_clientes;i++){
		clients[i]->stop_ex();
		//std::cout << "poasaa aca" << std::endl;
		clients[i]->join();
		delete clients[i];
	}
	socket.Shutdown(2);
	std::cout << "asd" << std::endl;
	//this->join();
}
