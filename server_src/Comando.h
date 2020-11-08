#ifndef SERVER_SRC_COMANDO_H_
#define SERVER_SRC_COMANDO_H_

#include <string>
#include <tuple>

class Comando{
private:
public:
	Comando(){
	}

	virtual std::string Obtener_Respuesta()= 0;

	virtual ~Comando();
};



#endif /* SERVER_SRC_COMANDO_H_ */
