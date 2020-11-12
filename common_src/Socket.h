#ifndef COMMON_SRC_SOCKET_H_
#define COMMON_SRC_SOCKET_H_
#include <sys/types.h>
#define INVALID_FD -1

class Socket{
private:
	int fd;

public:
	//Constructor por default si no me pasan ningun fd
	 Socket():fd(INVALID_FD){
	}

	 //Constructor si me pasan un fd como parametro
	 explicit Socket(int i):fd(i){
	 }

	 /* LO MARCO COMO NO COPIABLE */

	 Socket& operator=(const Socket &other) = delete;

	 Socket(const Socket &other) = delete;

	 /* MOVE SEMANTICS */

	 Socket(Socket &&other);

	 Socket &operator=(Socket &&other);

	 void Connect(const char *host, const char *service);

	 void Bind_And_Listen(const char *host,const char *service);

	 Socket Accept();

	 ssize_t Send(char *buffer, size_t length);

	 ssize_t Receive(char *buffer, size_t length);

	 void Close();

	 void Shutdown(int canal);

	 void setToInvalidFd();

	~Socket();
};


#endif /* COMMON_SRC_SOCKET_H_ */
