#include "Server_Manager.h"
#include "../common_src/File.h"
#include "../common_src/Socket.h"
#include <sstream>
#include <vector>
#include <utility>
#include "../common_src/Socket_exception.h"
#include "../common_src/File_exception.h"
#define TAMANIO_BUFFER 64
#define CLOSED_FD -1
#define CERRAR_RD_WR 2

void Server_Manager::operator()(){
	start();
}

void Server_Manager::Guardar_Root(const std::string& FileName){
	std::ifstream ifs;
	ifs.open(FileName);
	if(!ifs){
		throw FileException("Error al leer el archivo \n");
	}
	std::string cuerpo;
	cuerpo.assign((std::istreambuf_iterator<char>(ifs)),
		            std::istreambuf_iterator<char>());
	hash_recursos["/"]=cuerpo;
	ifs.close();
}


void Server_Manager::run(){
	Socket peer;
	while (true){
		try{
			peer=listener.Accept();
		}
		catch(SocketException &except_msg){
			break;
		}
		cant_clientes++;
		ThClient* client= new ThClient(std::move(peer),monitor);
		clients.push_back(client);
		client->start();
		clean_zombies();
	}
}


void Server_Manager::clean_zombies(){
	for (std::vector<ThClient*>::iterator it = clients.begin();\
		it != clients.end();){
		if (!(*it)->is_alive()){
			(*it)->join();
			delete *it;
			cant_clientes--;
			it = clients.erase(it);
	    }else{
	    	++it;
	    }
	  }
}


void Server_Manager::stop_running(){
	listener.Shutdown(CERRAR_RD_WR);
	listener.Close();
	listener.setToInvalidFd();
}


Server_Manager::~Server_Manager(){
	for (int i=0; i<cant_clientes; i++){
		clients[i]->join();
		delete clients[i];
	}
}
