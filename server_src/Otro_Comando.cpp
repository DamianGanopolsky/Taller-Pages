#include "Otro_Comando.h"
#include <string>


std::string Otro_Comando::Obtener_Respuesta(){
	std::string respuesta= \
			"HTTP 405/1.1 METHOD NOT ALLOWED\n\nPUT es un comando desconocidoo";
	return respuesta;
}

Otro_Comando::~Otro_Comando(){
}




