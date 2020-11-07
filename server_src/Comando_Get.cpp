#include "Comando_Get.h"
#include <iostream>

std::string Comando_Get::Obtener_Respuesta(){

	std::string respuesta;
	if(std::get<1>(datos_petitorio).compare("/")==0){
		respuesta=hash["/"];
	}
	else{
		if (hash.find(std::get<1>(datos_petitorio)) == hash.end()){
			/* NO EXISTE LA KEY */
			respuesta="HTTP 404 NOT FOUND\n\n";
		}
		else{
			respuesta="Get de recurso";
			hash[std::get<1>(datos_petitorio)];
		}
	}
	return respuesta;
}

Comando_Get::~Comando_Get(){

}

