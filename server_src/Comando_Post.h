#ifndef SERVER_SRC_COMANDO_POST_H_
#define SERVER_SRC_COMANDO_POST_H_
#include "Comando.h"
#include <unordered_map>
#include <string>
#include <tuple>
#include <mutex>


class Comando_Post: public Comando{
private:
	//La tupla datos_petitorio, contendra como primer valor el tipo
	//de comando, seguido del recurso al que se refiere y por ultimo
	//contendra el cuerpo del mensaje.
	std::tuple<std::string,std::string,std::string> datos_petitorio;
	std::unordered_map<std::string, std::string>& hash;
	std::mutex m;

public:
	Comando_Post(const std::tuple<std::string,std::string,std::string>& petitorio\
	,std::unordered_map<std::string, std::string>& hash_recursos):\
	 datos_petitorio(petitorio),hash(hash_recursos){
	}

	std::string Obtener_Respuesta() override;

	~Comando_Post();
};



#endif /* SERVER_SRC_COMANDO_POST_H_ */
