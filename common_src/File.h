#ifndef COMMON_SRC_FILE_H_
#define COMMON_SRC_FILE_H_
#include <fstream>
#include <string>


class File{
private:
	std::ifstream* inputFile;
	//Lo marco como no copiable a File
	File(const File &other) = delete;
	File& operator=(const File &other) = delete;

public:
	explicit File(const std::string &file_name){
		inputFile = new std::ifstream;
		inputFile->open(file_name, std::ios::in);
		if(!inputFile){
			throw "Error al abrir el archivo";
		}
	}


	void Assign(std::string &cuerpo);

	//Devuelve true si se encuentra en el fin de archivo, y devuelve false en
	//el caso de que no se encuentre en el final
	bool end() const;

	~File();
};



#endif /* COMMON_SRC_FILE_H_ */
