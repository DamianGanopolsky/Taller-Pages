#ifndef SERVER_SRC_SERVER_MANAGER_H_
#define SERVER_SRC_SERVER_MANAGER_H_
#include <string>
#include <unordered_map>

class Server_Manager{
private:

	std::unordered_map<std::string, std::string> hash_recursos;
public:
	void Guardar_Root(std::string FileName);

	void Receive_connections(const char* Port);

};



#endif /* SERVER_SRC_SERVER_MANAGER_H_ */
