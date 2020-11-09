#ifndef CLIENT_SRC_CLIENT_MANAGER_H_
#define CLIENT_SRC_CLIENT_MANAGER_H_
#include <string>
#include "../common_src/Socket.h"


class Client_Manager{
private:
	const char* ip;
	const char* port;
	Socket socket;

public:
	 Client_Manager(const char* ip_argv,const char* port_argv):\
	 ip(ip_argv),port(port_argv){
	}
	 void enviar_al_server();

	 void recibir_del_server();

	~Client_Manager();
};



#endif
