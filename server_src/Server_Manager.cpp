#include "Server_Manager.h"
#include "../common_src/File.h"
#include "../common_src/Socket.h"
#include "Parser.h"
#include "Comando_Post.h"
#include "Comando_Get.h"
#include "Comando.h"
#include <cstring>
#include <tuple>

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
		char buff[5];
		while(recibidos!=0){
			recibidos=peer.Receive(buff,5);
			input.append(buff);
			memset(buff,0,sizeof(buff));
		}
}

void Server_Manager::Response(){
	Parser parser(input);
	auto datos_petitorio=parser.Parsear_Archivo();
	Comando_Post comando(datos_petitorio);
	Comando_Get comando_get(datos_petitorio);
	std::string respuesta_get=comando_get.Obtener_Respuesta();
	std::string respuesta=comando.Obtener_Respuesta();
}


Server_Manager::~Server_Manager(){

}
