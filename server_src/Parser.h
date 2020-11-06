#ifndef SERVER_SRC_PARSER_H_
#define SERVER_SRC_PARSER_H_
#include <string>
#include <tuple>

class Parser{
private:
	std::string &texto;

public:
	explicit Parser(std::string &Linea):texto(Linea){
	}

	std::tuple<std::string,std::string,std::string> Parsear_Archivo();

	~Parser();
};




#endif /* SERVER_SRC_PARSER_H_ */
