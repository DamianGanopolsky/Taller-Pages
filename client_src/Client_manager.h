#ifndef CLIENT_SRC_CLIENT_MANAGER_H_
#define CLIENT_SRC_CLIENT_MANAGER_H_
#include <string>
#include "../common_src/Socket.h"


class Receptor_input{
private:
	const char* ip;
	const char* port;
	Socket socket;

public:
	 Receptor_input(const char* ip_argv,const char* port_argv):\
	 ip(ip_argv),port(port_argv),socket(-1){
	}
	 void enviar_al_server();

	 void recibir_del_server();


	~Receptor_input();
};



#endif
