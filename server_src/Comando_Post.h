#ifndef SERVER_SRC_COMANDO_POST_H_
#define SERVER_SRC_COMANDO_POST_H_
#include "Comando.h"
#include <unordered_map>


class Comando_Post: public Comando{
private:
	std::tuple<std::string,std::string,std::string> datos_petitorio;
	std::unordered_map<std::string, std::string>& hash;

public:
	Comando_Post(std::tuple<std::string,std::string,std::string> petitorio,\
	std::unordered_map<std::string, std::string>& hash_recursos):\
	 datos_petitorio(petitorio),hash(hash_recursos){
	}

	std::string Obtener_Respuesta();

	~Comando_Post();
};



#endif /* SERVER_SRC_COMANDO_POST_H_ */
