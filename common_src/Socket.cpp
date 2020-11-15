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
    hints.ai_flags = 0;
    hints.ai_protocol = 0;
    codigo_getaddrinfo = getaddrinfo(host, service, &hints, &result);
    if (codigo_getaddrinfo != 0) {
    	fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(codigo_getaddrinfo));
    	return;
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
    	fprintf(stderr, "No se pudo conectar\n");
    	return;
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
        fprintf(stderr, "No se pudo hacer el bind\n");
        return;
    }
    freeaddrinfo(result);
    listen(fdscriptor, LONGITUD_COLA);
    fd=fdscriptor;
}


Socket Socket::Accept(){
    char addressBuf[INET_ADDRSTRLEN];
    struct sockaddr_in address;
    socklen_t addressLength = (socklen_t) sizeof(address);
    int newFd = accept(fd, \
    		(struct sockaddr *)&address,&addressLength);
    if (newFd==-1){
    	throw SocketException("Listener cerrado \n");
    }
    inet_ntop(AF_INET, &(address.sin_addr), addressBuf, INET_ADDRSTRLEN);
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
        	printf("Error al leer %s\n", strerror(errno));
        	break;
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
			fprintf(stderr,"Error al recibir \n");
			break;
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
	if(canal==0){
		shutdown(fd,SHUT_RD);
	}
	if(canal==1){
		shutdown(fd,SHUT_WR);
	}
	if(canal==2){
		shutdown(fd,SHUT_RDWR);
	}
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
