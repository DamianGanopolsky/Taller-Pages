#include <iostream>
#include "../common_src/Socket.h"

int main(int argc,char* argv[]){

	for(int i=0;i<argc;i++){
		std::cout << argv[i] << std::endl;
	}

	Socket socket(-1);
	socket.Bind_And_Listen(NULL,argv[1]);
	Socket peer=socket.Accept();
	size_t recibidos=1;
	char buff[64];
	while(recibidos!=0){
		recibidos=peer.Receive(buff,sizeof(buff));
		fwrite(buff,1,recibidos,stdout);
	}
	return 0;
}
