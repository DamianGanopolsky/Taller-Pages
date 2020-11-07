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
	Socket socket(CLOSED_FD);
	socket.Bind_And_Listen(NULL,port_to_listen);
	std::vector<ThClient*> clients;
	//Socket peer=socket.Accept();
	//ThClient* client= new ThClient(std::move(peer),hash_recursos);
	//client->run();
	int total_clients=0;
	Socket peer(-1);

	while(keep_looping){
		try{
			peer=socket.Accept();
			total_clients++;
			clients.reserve(1);
			ThClient* client= new ThClient(std::move(peer),hash_recursos);
			client->start();
			std::cout << "asd3" << std::endl;
			clients.push_back(client);
			//client->join();
			if(total_clients==1){
				//socket.Close();
				break;
			}
		}
		catch(SocketException &except_msg){
			throw except_msg;
		}
	}
	for(int i=0;i<1;i++){
		//clients[i]->stop_ex();
		clients[i]->join();
		delete clients[i];
	}
}

void Server_Manager::Stop_Looping(){
	keep_looping=false;

}


Server_Manager::~Server_Manager(){

}
