#include "Comando_Get.h"
#include <string>
#define RECURSO 1

std::string Comando_Get::Obtener_Respuesta(){
	std::string respuesta;
	if (std::get<RECURSO>(datos_petitorio).compare("/")==0){
		respuesta="HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
		respuesta.append(hash["/"]);
	}else{ /* NO EXISTE LA KEY */
		if (hash.find(std::get<RECURSO>(datos_petitorio)) == hash.end()){
			respuesta="HTTP 404 NOT FOUND\n\n";
		}else{
			respuesta="Get de recurso";
			hash[std::get<RECURSO>(datos_petitorio)];
		}
	}
	return respuesta;
}

Comando_Get::~Comando_Get(){
}

