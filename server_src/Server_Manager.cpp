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
#define TAMANIO_BUFFER 64

void Server_Manager::Guardar_Root(std::string FileName){
	File archivo(FileName);
	int longitud_archivo=archivo.longitud_archivo();
	std::string cuerpo;
	cuerpo.reserve(longitud_archivo);
	archivo.Asign(cuerpo);
	hash_recursos["/"]=cuerpo;
}


void Server_Manager::Receive_connections(const char* Port){
		Socket socket(-1);
		socket.Bind_And_Listen(NULL,Port);
		Socket peer=socket.Accept();
		ssize_t recibidos=1;
		char buff[TAMANIO_BUFFER];
		while(recibidos!=0){
			recibidos=peer.Receive(buff,TAMANIO_BUFFER);
			input.append(buff,recibidos);
			memset(buff,0,sizeof(buff));
		}

		Parser parser(input);
		auto datos_petitorio=parser.Parsear_Archivo();
		std::string respuesta_al_cliente;

		if(std::get<0>(datos_petitorio).compare("GET")==0){
			Comando_Get comando_get(datos_petitorio,hash_recursos);
			respuesta_al_cliente=comando_get.Obtener_Respuesta();
		}
		else if(std::get<0>(datos_petitorio).compare("POST")==0){
			Comando_Post comando(datos_petitorio,hash_recursos);
			respuesta_al_cliente=comando.Obtener_Respuesta();
		}
		else{
			Otro_Comando otro_comando(datos_petitorio,hash_recursos);
			respuesta_al_cliente=otro_comando.Obtener_Respuesta();
		}

		//std::cout << "input es " << input << std::endl;
		//std::cout << "respuesta es:" << respuesta_al_cliente << std::endl;
		//std::string texto="Texto";
		std::istringstream iss(respuesta_al_cliente);
		while(!iss.eof()){

			char buffer[TAMANIO_BUFFER];
			iss.read(buffer,TAMANIO_BUFFER);
			peer.Send(buffer,iss.gcount());
		}
}

void Server_Manager::Response(){
	Parser parser(input);
	auto datos_petitorio=parser.Parsear_Archivo();
	std::string respuesta_al_cliente;

	if(std::get<0>(datos_petitorio).compare("GET")==0){
		Comando_Get comando_get(datos_petitorio,hash_recursos);
		respuesta_al_cliente=comando_get.Obtener_Respuesta();
	}
	else if(std::get<0>(datos_petitorio).compare("POST")==0){
		Comando_Post comando(datos_petitorio,hash_recursos);
		respuesta_al_cliente=comando.Obtener_Respuesta();
	}
	else{
		Otro_Comando otro_comando(datos_petitorio,hash_recursos);
		respuesta_al_cliente=otro_comando.Obtener_Respuesta();
	}

	std::cout << respuesta_al_cliente << std::endl;
}


Server_Manager::~Server_Manager(){

}
