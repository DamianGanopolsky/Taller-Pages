#define _POSIX_C_SOURCE 200112L
#define LONGITUD_COLA 10
#define INVALID_FD -1
#include "Socket.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "Socket_exception.h"
#include <iostream>

//Move semantics
Socket::Socket(Socket &&other) {
    this->fd = other.fd;
    other.fd = INVALID_FD;
}

//Move semantics
Socket &Socket::operator=(Socket &&other) {
    this->fd = other.fd;
    other.fd = INVALID_FD;
    return *this;
}


void Socket::Connect(const char *host, const char *service){
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int codigo_getaddrinfo,socketfd=-1;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_protocol = 0;
    codigo_getaddrinfo = getaddrinfo(host, service, &hints, &result);
    if (codigo_getaddrinfo != 0) {
    	throw SocketException("Error en getaddrinfo \n");
    }
    for (rp = result; rp != NULL; rp = rp->ai_next) {
    	socketfd = socket(rp->ai_family, rp->ai_socktype,rp->ai_protocol);
        if (socketfd == INVALID_FD)
        	continue;
        if (connect(socketfd, rp->ai_addr, rp->ai_addrlen) != -1)
        	break;
        close(socketfd);
    }
    fd=socketfd;
    freeaddrinfo(result);
    if (rp == NULL) {
    	throw SocketException("No se pudo conectar \n");
    }
}


void Socket::Bind_And_Listen(const char *host,const char *service){
    int fdscriptor = -1;
    struct addrinfo hints;
	struct addrinfo *result, *rp;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    //Obtengo la lista de resultados para el servicio
    getaddrinfo(NULL, service, &hints, &result);
	int val_opt=1;

	//Itero la lista, si no puedo bindear sigo intentando
	//con los siguientes resultados
    for (rp = result; rp != NULL; rp = rp->ai_next) {
    	fdscriptor = socket(rp->ai_family,rp->ai_socktype,rp->ai_protocol);
    	setsockopt(fdscriptor,SOL_SOCKET,SO_REUSEADDR,&val_opt,sizeof(val_opt));
        if (fdscriptor == INVALID_FD)
            continue;
        if (bind(fdscriptor, rp->ai_addr, rp->ai_addrlen) == 0)
            break;                  /* Success */
        close(fdscriptor);
    }
    if (rp == NULL) {               /* No address succeeded */
    	throw SocketException("No se pudo hacer el bind\n");
    }
    freeaddrinfo(result);
    listen(fdscriptor, LONGITUD_COLA);
    fd=fdscriptor;
}


Socket Socket::Accept(){
    int newFd = accept(fd,NULL,NULL);
    if (newFd==-1){
    	throw SocketException("Listener cerrado \n");
    }
    return Socket(newFd);
}

ssize_t Socket::Send(char* buffer, size_t length){
	ssize_t longitud_restante=length;
	char* puntero_a_caracter_actual=buffer;

    while (longitud_restante>0){
    	ssize_t caracteres_enviados;
    	caracteres_enviados=send(fd,puntero_a_caracter_actual\
    			,longitud_restante,MSG_NOSIGNAL);
    	// Si caracteres enviados=-1, hubo un error en el intento de envio
        if (caracteres_enviados==-1){
        	std::cout << strerror(errno) << std::endl;
        	throw SocketException("Error al leer \n");
        }
        puntero_a_caracter_actual=puntero_a_caracter_actual+caracteres_enviados;
        longitud_restante=longitud_restante-caracteres_enviados;
    }
    return longitud_restante;
}


ssize_t Socket::Receive(char *buffer, size_t length){
	ssize_t longitud_restante=length;
	char* puntero_a_caracter_actual=buffer;

	while (longitud_restante>0){
		ssize_t caracteres_recibidos;

		caracteres_recibidos=recv(fd,puntero_a_caracter_actual\
				,longitud_restante,0);
		//Si es -1, hubo un error al recibir
		if (caracteres_recibidos==-1){
			throw SocketException("Error al recibir \n");
		}else if (caracteres_recibidos==0){//Si es 0, llegue al "
			return length-longitud_restante; // end of file", paro de recibir
		}else{
	        puntero_a_caracter_actual=puntero_a_caracter_actual\
	        		+caracteres_recibidos;

	        longitud_restante=longitud_restante-caracteres_recibidos;
		}
	}
	return length-longitud_restante;
}

void Socket::setToInvalidFd(){
	fd=INVALID_FD;
}


void Socket::Shutdown(int canal){
	shutdown(fd,canal);
}


void Socket::Close(){
	close(fd);
}


Socket::~Socket(){
	if(fd!=INVALID_FD){
		shutdown(fd,SHUT_RDWR);
		close(fd);
	}
}
