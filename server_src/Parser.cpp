#include "Parser.h"
#include <sstream>
#include <iostream>


std::tuple<std::string,std::string,std::string> Parser::Parsear_Archivo(){
	std::tuple <std::string,std::string,std::string> datos_petitorio;
	std::string tipo_de_petitorio,resource,body,linea;
	std::istringstream iss(texto);

	while (std::getline(iss, linea)){
		std::cout << linea << std::endl;
	}

	return datos_petitorio;

}




