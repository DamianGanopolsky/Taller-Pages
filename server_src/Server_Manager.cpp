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
	Socket Peer(-1);
	Peer=socket.Accept();
	ssize_t recibidos=1;
	char buff[TAMANIO_BUFFER];
	std::string input;
	while (recibidos!=0){
		recibidos=Peer.Receive(buff,TAMANIO_BUFFER);
		input.append(buff,recibidos);
		memset(buff,0,sizeof(buff));
	}
	std::string primera_linea=input.substr(0,input.find("\n"));
	std::cout << primera_linea << std::endl;
	Parser parser(input);
	auto datos_petitorio=parser.Parsear_Archivo();
	std::string respuesta_al_cliente;
	if (std::get<0>(datos_petitorio).compare("GET")==0){
		Comando_Get comando_get(datos_petitorio,hash_recursos);
		respuesta_al_cliente=comando_get.Obtener_Respuesta();
	}else if (std::get<0>(datos_petitorio).compare("POST")==0){
		Comando_Post comando(datos_petitorio,hash_recursos);
		respuesta_al_cliente=comando.Obtener_Respuesta();
	}else{
		Otro_Comando otro_comando(datos_petitorio,hash_recursos);
		respuesta_al_cliente=otro_comando.Obtener_Respuesta();
	}
	std::istringstream iss(respuesta_al_cliente);
	while (!iss.eof()){
		char buffer[TAMANIO_BUFFER];
		iss.read(buffer,TAMANIO_BUFFER);
		Peer.Send(buffer,iss.gcount());
	}
	Peer.Shutdown(CERRAR_RD_WR);
/*		Socket peer(-1);
	while (true){
		try{
			peer=socket.Accept();
		}
		catch(SocketException &except_msg){
			break;
		}
		cant_clientes++;
		ThClient* client= new ThClient(std::move(peer),hash_recursos);
		clients.push_back(client);
		client->start();
		} */
}

void Server_Manager::clean(){
	socket.Shutdown(CERRAR_RD_WR);
	socket.Close();
	socket.setToInvalidFd();
	std::cout << "asd" << std::endl;
}


Server_Manager::~Server_Manager(){
/*	for (int i=0; i<cant_clientes; i++){
		clients[i]->stop_ex();
		clients[i]->join();
		delete clients[i];
	} */
}
