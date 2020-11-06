#include "Server_Manager.h"
#include "../common_src/File.h"
#include "../common_src/Socket.h"
#include "Parser.h"
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

}


Server_Manager::~Server_Manager(){

}
