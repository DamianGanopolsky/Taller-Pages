#ifndef SERVER_SRC_SERVER_MANAGER_H_
#define SERVER_SRC_SERVER_MANAGER_H_
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include "ThClient.h"

class Server_Manager: public Thread{
private:
	std::unordered_map<std::string, std::string> hash_recursos;
	std::string input;
	std::vector<ThClient*> clients;
	Socket listener;
	int cant_clientes;

	void clean_zombies();

public:
	explicit Server_Manager(const char* service):\
	cant_clientes(0){
		listener.Bind_And_Listen(NULL,service);
		clients.clear();
	}

	void run() override;

	//SObrecarga del operador (), requisito de la entrega
	void operator()();

	//Guarda el archivo que se correspondera con el recurso "/"
	void Guardar_Root(const std::string& FileName);

	//Este metodo sera llamado por el hilo de server_main, se busca
	//que se termine la ejecucion de los distintos hilos correctamente
	void stop_running();

	~Server_Manager();
};



#endif /* SERVER_SRC_SERVER_MANAGER_H_ */
