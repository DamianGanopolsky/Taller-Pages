#include "Comando_Post.h"
#include <string>
#define RECURSO 1
#define BODY 2


std::string Comando_Post::Obtener_Respuesta(){
	std::string respuesta;
	if (std::get<RECURSO>(datos_petitorio).compare("/")==0){
		respuesta="HTTP/1.1 403 FORBIDDEN\n\n";
	}else{
		hash[std::get<RECURSO>(datos_petitorio)]=std::get<BODY>(datos_petitorio);
		respuesta="HTTP/1.1 200 OK\n\n";
		respuesta.append(std::get<BODY>(datos_petitorio));
	}
	return respuesta;
}


Comando_Post::~Comando_Post(){
}

