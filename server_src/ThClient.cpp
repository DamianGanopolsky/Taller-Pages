#include "ThClient.h"
#include "Parser.h"
#include "Otro_Comando.h"
#include "Comando_Post.h"
#include "Comando_Get.h"
#include "Comando.h"
#include "Parser.h"
#include <iostream>
#include <cstring>
#include <sstream>
#define TAMANIO_BUFFER 64


void ThClient::send_answer(std::string server_answer){
	std::istringstream iss(server_answer);
	while(!iss.eof()){

		char buffer[TAMANIO_BUFFER];
		iss.read(buffer,TAMANIO_BUFFER);
		Peer.Send(buffer,iss.gcount());
	}
	Peer.Shutdown(2);
}


void ThClient::process_command(std::string input_client){
	Parser parser(input_client);
	auto datos_petitorio=parser.Parsear_Archivo();
	std::string respuesta_al_cliente;

	if(std::get<0>(datos_petitorio).compare("GET")==0){
		Comando_Get comando_get(datos_petitorio,hash);
		respuesta_al_cliente=comando_get.Obtener_Respuesta();
	}
	else if(std::get<0>(datos_petitorio).compare("POST")==0){
		Comando_Post comando(datos_petitorio,hash);
		respuesta_al_cliente=comando.Obtener_Respuesta();
	}
	else{
		Otro_Comando otro_comando(datos_petitorio,hash);
		respuesta_al_cliente=otro_comando.Obtener_Respuesta();
	}
	this->send_answer(respuesta_al_cliente);
}

void ThClient::stop_ex(){
	keep_talking=false;
	Peer.Shutdown(2);
	Peer.Close();
}


void ThClient::run(){
	while(keep_talking){
		ssize_t recibidos=1;
		char buff[TAMANIO_BUFFER];
		std::string input;
		while(recibidos!=0){
			recibidos=Peer.Receive(buff,TAMANIO_BUFFER);
			input.append(buff,recibidos);
			memset(buff,0,sizeof(buff));
		}
		std::cout << input << std::endl;
		this->process_command(input);
		keep_talking=false;
	}
	is_running=false;
}

