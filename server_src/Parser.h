#ifndef SERVER_SRC_PARSER_H_
#define SERVER_SRC_PARSER_H_
#include <string>
#include <tuple>

class Parser{
private:
	const std::string &texto;

	void Obtener_Key_Recurso(const std::string& linea,std::string& recurso);

	void Obtener_Cabecera(const std::string& linea,\
			std::string& tipo_petitorio,std::string& resource);

public:
	explicit Parser(const std::string &Linea):texto(Linea){
	}

	//La tupla a devolver contendra como primer valor el tipo
	//de comando, seguido del recurso al que se refiere y por ultimo
	//contendra el cuerpo del mensaje.
	std::tuple<std::string,std::string,std::string> Parsear_Archivo();

	~Parser();
};




#endif /* SERVER_SRC_PARSER_H_ */
