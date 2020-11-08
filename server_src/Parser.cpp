#include "Parser.h"
#include <sstream>
#include <iostream>
#define FIRST_LINE 1
#define HEADER_LINE 2
#define BODY_LINE 3

void Obtener_Key_Recurso(std::string& linea,std::string& recurso){
	std::string subline_res=linea.substr(linea.find('/'));
	if(subline_res.at(1)==' '){
		recurso="/";
	}else{
		recurso=subline_res.substr(1,subline_res.find(' '));
	}
}

void Obtener_Cabecera(std::string& linea,\
		std::string& tipo_petitorio,std::string& resource){
	if (linea.find("GET")!= std::string::npos){
		tipo_petitorio="GET";
		Obtener_Key_Recurso(linea,resource);
	}else if (linea.find("POST")!= std::string::npos){
		tipo_petitorio="POST";
		Obtener_Key_Recurso(linea,resource);
	}else{
		tipo_petitorio="OTROMETODO";
	}
}


std::tuple<std::string,std::string,std::string> Parser::Parsear_Archivo(){
	std::tuple <std::string,std::string,std::string> datos_petitorio;
	std::string tipo_de_petitorio,resource,body,line;
	std::istringstream iss(texto);
	int tipo_de_linea=FIRST_LINE;
	while (std::getline(iss, line)){
		if (tipo_de_linea==FIRST_LINE){
			Obtener_Cabecera(line,tipo_de_petitorio,resource);
			tipo_de_linea=HEADER_LINE;
		}
		if (line.empty()){
			tipo_de_linea=BODY_LINE;
			continue;
		}
		if (tipo_de_linea==BODY_LINE){
			body.append(line);
			body.append("\n");
		}
	}
	datos_petitorio=make_tuple(tipo_de_petitorio,resource,body);
	return datos_petitorio;
}

Parser::~Parser(){
}


