#ifndef SERVER_SRC_COMANDO_POST_H_
#define SERVER_SRC_COMANDO_POST_H_
#include "Comando.h"


class Comando_Post: public Comando{
private:
	std::tuple<std::string,std::string,std::string> datos_petitorio;

public:
	Comando_Post(std::tuple<std::string,std::string,std::string> petitorio)\
	: datos_petitorio(petitorio){
	}

	std::string Obtener_Respuesta();

	~Comando_Post();
};



#endif /* SERVER_SRC_COMANDO_POST_H_ */
