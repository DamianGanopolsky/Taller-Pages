#ifndef CLIENT_SRC_RECEPTOR_INPUT_H_
#define CLIENT_SRC_RECEPTOR_INPUT_H_
#include <string>


class Receptor_input{
private:
	const char* ip;
	const char* port;

public:
	 Receptor_input(const char* ip_argv,const char* port_argv):\
	 ip(ip_argv),port(port_argv){
	};
	 void recibir();


	~Receptor_input();
};



#endif
