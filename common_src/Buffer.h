

#ifndef COMMON_SRC_BUFFER_H_
#define COMMON_SRC_BUFFER_H_
#include <stdlib.h>

class Buffer{
char *buf;
//Encapsulo todo lo que pide recursos en una clase.
//En el destructor libero todo
public:
	Buffer(size_t count) : buf(nullptr) {
	buf = (char*) malloc(sizeof(char)*count);
	if (!buf) { throw -1; }

}


	~Buffer();
};



#endif /* COMMON_SRC_BUFFER_H_ */
