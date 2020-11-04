#ifndef CLIENT_SRC_RECEPTOR_INPUT_H_
#define CLIENT_SRC_RECEPTOR_INPUT_H_
#include <string>


class Receptor_input{
private:
	std::string ip;
	std::string port;

public:
	 Receptor_input(std::string ip_argv,std::string port_argv):\
	 ip(ip_argv),port(port_argv){
	};
	 void recibir();


	~Receptor_input();
};



#endif
