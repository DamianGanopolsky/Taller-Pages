#ifndef COMMON_SRC_FILE_H_
#define COMMON_SRC_FILE_H_

#include <iostream>
#include <fstream>
#include <string>


class File{
private:
	std::ifstream *inputFile;

public:
	explicit File(const std::string &file_name){
		inputFile = new std::ifstream;
		inputFile->open(file_name, std::ios::in);
	}
	//Lee una linea del archivo, devuelve esta linea como string y avanza una
	//linea en la lectura del archivo.
	std::string getLine();

	int longitud_archivo();

	void Asign(std::string &cuerpo);

	//Devuelve true si se encuentra en el fin de archivo, y devuelve false en
	//el caso de que no se encuentre en el final
	bool end() const;

	~File();
};



#endif /* COMMON_SRC_FILE_H_ */
