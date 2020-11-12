#include "Monitor_Respuesta.h"
#include "Otro_Comando.h"
#include "Comando_Post.h"
#include "Comando_Get.h"
#include "Comando.h"
#include <tuple>
#include <string>

void Monitor_Respuesta::Respuesta_Servidor(const std::tuple<std::string,\
		std::string,std::string>petitorio,std::string& respuesta_al_cliente){
	std::unique_lock<std::mutex> lock(m);
	if (std::get<0>(petitorio).compare("GET")==0){
		Comando_Get comando_get(petitorio,protected_hash);
		respuesta_al_cliente=comando_get.Obtener_Respuesta();
	}else if (std::get<0>(petitorio).compare("POST")==0){
		Comando_Post comando(petitorio,protected_hash);
		respuesta_al_cliente=comando.Obtener_Respuesta();
	}else{
		Otro_Comando otro_comando(petitorio,protected_hash);
		respuesta_al_cliente=otro_comando.Obtener_Respuesta();
	}
}


Monitor_Respuesta::~Monitor_Respuesta(){
}


