#include <iostream>
#include "../common_src/Socket.h"

int main(int argc,char* argv[]){

	for(int i=0;i<argc;i++){
		std::cout << "argv es" << argv[i] << std::endl;
	}

	Socket socket(-1);
	socket.Bind_And_Listen(NULL,argv[1]);
	Socket peer=socket.Accept();
	size_t recibidos=1;
	//std::string buf;
	char buff[64];
	while(recibidos!=0){
		recibidos=peer.Receive(buff,64);
		std::cout << buff << std::endl;
	//	fwrite(buf,1,recibidos,stdout);
	}
	return 0;
}
