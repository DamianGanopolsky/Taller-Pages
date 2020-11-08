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
#include <utility>
#include "../common_src/Socket_exception.h"
#define TAMANIO_BUFFER 64
#define CLOSED_FD -1
#define CERRAR_RD_WR 2


void Server_Manager::Guardar_Root(std::string FileName){
	File archivo(FileName);
	int longitud_archivo=archivo.longitud_archivo();
	std::string cuerpo;
	cuerpo.reserve(longitud_archivo);
	archivo.Asign(cuerpo);
	hash_recursos["/"]=cuerpo;
}


void Server_Manager::run(){
	Socket peer(-1);
	while (true){
		try{
			peer=socket.Accept();
		}
		catch(SocketException &except_msg){
			throw;
		}
		cant_clientes++;
		ThClient* client= new ThClient(std::move(peer),hash_recursos);
		clients.push_back(client);
		client->start();
		}
}
/*
void Server_Manager::Stop_Looping(){
	keep_looping=false;
	for (int i=0;i<cant_clientes;i++){
		clients[i]->stop_ex();
		clients[i]->join();
		delete clients[i];
	}
	socket.Shutdown(CERRAR_RD_WR);
	//socket.Close();
}
*/

Server_Manager::~Server_Manager(){
	keep_looping=false;
	for (int i=0; i<cant_clientes; i++){
		clients[i]->stop_ex();
		clients[i]->join();
		delete clients[i];
	}
	socket.Shutdown(CERRAR_RD_WR);
}
