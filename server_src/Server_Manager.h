#ifndef SERVER_SRC_SERVER_MANAGER_H_
#define SERVER_SRC_SERVER_MANAGER_H_
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include "ThClient.h"

class Server_Manager: public Thread{
private:

	std::unordered_map<std::string, std::string> hash_recursos;
	std::string input;
	std::vector<ThClient*> clients;
	Socket& socket;
	//const char* port_to_listen;
	std::atomic<bool> keep_looping;

public:

	explicit Server_Manager(Socket& sock):socket(sock),keep_looping(true){
		clients.reserve(2);
		clients.clear();
	}

	void run();

	void Guardar_Root(std::string FileName);

	void Receive_connections(const char* Port);

	void Stop_Looping();

	~Server_Manager();

};



#endif /* SERVER_SRC_SERVER_MANAGER_H_ */
