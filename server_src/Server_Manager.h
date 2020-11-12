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
	explicit Server_Manager(Socket sock):listener(std::move(sock)),\
	cant_clientes(0){
		clients.clear();
	}

	void run() override;

	void operator()();

	void Guardar_Root(const std::string& FileName);

	void stop_running();

	~Server_Manager();
};



#endif /* SERVER_SRC_SERVER_MANAGER_H_ */
