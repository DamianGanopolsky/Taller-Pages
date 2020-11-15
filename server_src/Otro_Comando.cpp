#include "Otro_Comando.h"
#include <string>


std::string Otro_Comando::Obtener_Respuesta(){
	std::string respuesta= \
			"HTTP/1.1 405 METHOD NOT ALLOWED\n\nPUT es un comando desconocido";
	return respuesta;
}

Otro_Comando::~Otro_Comando(){
}




