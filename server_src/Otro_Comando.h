#ifndef SERVER_SRC_OTRO_COMANDO_H_
#define SERVER_SRC_OTRO_COMANDO_H_

#include "Comando.h"
#include <unordered_map>

class Otro_Comando: public Comando{
private:
	std::tuple<std::string,std::string,std::string> datos_petitorio;
	std::unordered_map<std::string, std::string>& hash;

public:
	Otro_Comando(const std::tuple<std::string,std::string,std::string>\
			& petitorio,std::unordered_map<std::string,std::string>& hash_recursos)\
	: datos_petitorio(petitorio),hash(hash_recursos){
	}

	std::string Obtener_Respuesta();

	~Otro_Comando();
};


#endif /* SERVER_SRC_OTRO_COMANDO_H_ */
