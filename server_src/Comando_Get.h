#ifndef SERVER_SRC_COMANDO_GET_H_
#define SERVER_SRC_COMANDO_GET_H_
#include "Comando.h"

class Comando_Get: public Comando{
private:
	std::tuple<std::string,std::string,std::string> datos_petitorio;

public:
	Comando_Get(std::tuple<std::string,std::string,std::string> petitorio)\
	: datos_petitorio(petitorio){
	}

	std::string Obtener_Respuesta();

	~Comando_Get();
};

#endif /* SERVER_SRC_COMANDO_GET_H_ */
