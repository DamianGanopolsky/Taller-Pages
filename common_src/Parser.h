#ifndef COMMON_SRC_PARSER_H_
#define COMMON_SRC_PARSER_H_

#include <string>

class Parser{
private:


public:
	Parser(){
	};

	std::string Obtener_linea_cuerpo(std::string linea);

	~Parser();
};



#endif /* COMMON_SRC_PARSER_H_ */
