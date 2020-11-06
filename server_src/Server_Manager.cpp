#include "Server_Manager.h"
#include "../common_src/File.h"
#include "../common_src/Socket.h"
#include <cstring>

void Server_Manager::Guardar_Root(std::string FileName){
	File archivo(FileName);
	int longitud_archivo=archivo.longitud_archivo();
	std::string cuerpo;
	cuerpo.reserve(longitud_archivo);
	archivo.Asign(cuerpo);
	hash_recursos["/"]=cuerpo;
	std::cout << cuerpo << std::endl;
}


void Server_Manager::Receive_connections(const char* Port){
		Socket socket(-1);
		socket.Bind_And_Listen(NULL,Port);
		Socket peer=socket.Accept();
		//std::string buf;
		ssize_t recibidos=1;
		char buff[5];
		std::string input;
		while(recibidos!=0){
			recibidos=peer.Receive(buff,5);
			input.append(buff);
			//std::cout << input << std::endl;
			memset(buff,0,sizeof(buff));
		//	fwrite(buf,1,recibidos,stdout);
		}
		std::cout << input << std::endl;


}
