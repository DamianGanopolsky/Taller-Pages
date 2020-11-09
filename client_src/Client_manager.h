#ifndef CLIENT_SRC_CLIENT_MANAGER_H_
#define CLIENT_SRC_CLIENT_MANAGER_H_
#include <string>


class Receptor_input{
private:
	const char* ip;
	const char* port;

public:
	 Receptor_input(const char* ip_argv,const char* port_argv):\
	 ip(ip_argv),port(port_argv){
	}
	 void comunicar_con_server();


	~Receptor_input();
};



#endif
