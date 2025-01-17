#include "ThClient.h"
#include "Parser.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#define TAMANIO_BUFFER 64
#define CERRAR_RD_WR 2


void ThClient::send_answer(const std::string& server_answer){
	std::istringstream iss(server_answer);
	while (!iss.eof()){
		char buffer[TAMANIO_BUFFER];
		iss.read(buffer,TAMANIO_BUFFER);
		Peer.Send(buffer,iss.gcount());
	}
	Peer.Shutdown(CERRAR_RD_WR);
	Peer.Close();
}


void ThClient::process_command(const std::string& input_client){
	std::string primera_linea=input_client.substr(0,input_client.find("\n")+1);
	std::cout << primera_linea;
	Parser parser(input_client);
	//La tupla datos_petitorio, contendra como primer valor el tipo
	//de comando, seguido del recurso al que se refiere y por ultimo
	//contendra el cuerpo del mensaje.
	auto datos_petitorio=parser.Parsear_Archivo();
	std::string respuesta_al_cliente;
	monitor.Respuesta_Servidor(datos_petitorio, respuesta_al_cliente);
	this->send_answer(respuesta_al_cliente);
}

bool ThClient::is_alive(){
	return !(is_dead);
}


void ThClient::run(){
	ssize_t recibidos=1;
	char buff[TAMANIO_BUFFER];
	std::string input; //Input contendra el mensaje completo enviado por el cliente
	while (recibidos!=0){
		recibidos=Peer.Receive(buff,TAMANIO_BUFFER);
		input.append(buff,recibidos);
		memset(buff,0,sizeof(buff));
	}
	this->process_command(input);
	is_dead=true;
}

