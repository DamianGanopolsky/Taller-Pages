#ifndef COMMON_SRC_SOCKET_H_
#define COMMON_SRC_SOCKET_H_
#include <sys/types.h>

class Socket{
private:
	int fd;

public:
	 explicit Socket(int FileDescriptor):fd(FileDescriptor){
	}

	 void Connect(const char *host, const char *service);

	 void Bind_And_Listen(const char *host,const char *service);

	 ssize_t Send(char *buffer, size_t length);

	 ssize_t Receive(char *buffer, size_t length);

	 Socket Accept();

	 /* LO MARCO COMO NO COPIABLE */

	 Socket& operator=(const Socket &other) = delete;

	 Socket(const Socket &other) = delete;

	 /* MOVE SEMANTICS */

	 Socket(Socket &&other);

	 Socket &operator=(Socket &&other);

	 void Close();

	 void Shutdown(int RD_WR);

	 void setToInvalidFd();

	~Socket();
};


#endif /* COMMON_SRC_SOCKET_H_ */
