#ifndef COMMON_SRC_SOCKET_H_
#define COMMON_SRC_SOCKET_H_
#include <sys/types.h>

class Socket{
private:
	int fd;

public:
	 Socket(int FileDescriptor):fd(FileDescriptor){
	};

	 void Connect(const char *host, const char *service);

	 void Bind_And_Listen(const char *host,const char *service);

	 ssize_t Send(char *buffer, size_t length);

	 ssize_t Receive(char *buffer, size_t length);

	 Socket Accept();

	 void Shutdown(int RD_WR);

	~Socket();
};



#endif /* COMMON_SRC_SOCKET_H_ */
