#ifndef SERVER_SRC_COMANDO_H_
#define SERVER_SRC_COMANDO_H_

#include <string>
#include <tuple>

class Comando{
private:
public:
	Comando(){
	}

	// "Interfaz", no tiene implementado ningun metodo. Se busca que
	//todas sus clases hijas respondan al mismo metodo para asi en un
	//futuro poder iterarlas sabiendo que responden al mismo metodo
	virtual std::string Obtener_Respuesta()= 0;

	virtual ~Comando();
};



#endif /* SERVER_SRC_COMANDO_H_ */
