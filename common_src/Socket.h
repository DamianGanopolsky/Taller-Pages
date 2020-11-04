#ifndef COMMON_SRC_SOCKET_H_
#define COMMON_SRC_SOCKET_H_
#include <sys/types.h>

class Socket{
private:
	int fd;

public:
	 Socket(int FileDescriptor):fd(FileDescriptor){
	};

	 void socket_connect(const char *host, const char *service);

	 void socket_bind_and_listen(const char *host,const char *service);

	 ssize_t socket_send( unsigned char *buffer, size_t length);

	 ssize_t socket_receive(unsigned char *buffer, size_t length);

	 Socket socket_accept();

	~Socket();
};



#endif /* COMMON_SRC_SOCKET_H_ */
