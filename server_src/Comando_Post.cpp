#include "Comando_Post.h"


std::string Comando_Post::Obtener_Respuesta(){
	std::string respuesta;
	if(std::get<1>(datos_petitorio).compare("/")==0){
		respuesta="HTTP 403 FORBIDDEN\n\n";
	}
	else{
		hash[std::get<1>(datos_petitorio)]=std::get<2>(datos_petitorio);
		respuesta="HTTP/1.1 200 OK\n";
		respuesta.append(std::get<2>(datos_petitorio));
	}
	return respuesta;
}


Comando_Post::~Comando_Post(){

}

