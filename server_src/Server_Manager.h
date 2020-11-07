#ifndef SERVER_SRC_SERVER_MANAGER_H_
#define SERVER_SRC_SERVER_MANAGER_H_
#include <string>
#include <unordered_map>
#include "ThClient.h"

class Server_Manager: public Thread{
private:

	std::unordered_map<std::string, std::string> hash_recursos;
	std::string input;
	//Socket listener;
	const char* port_to_listen;

public:

	Server_Manager(const char* port):port_to_listen(port){

	}

	void run();

	void Guardar_Root(std::string FileName);

	void Receive_connections(const char* Port);

	~Server_Manager();

};



#endif /* SERVER_SRC_SERVER_MANAGER_H_ */
