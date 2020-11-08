#include "File.h"
#include <string>


std::string File::getLine() {
	std::string line;
	std::getline(*inputFile, line);
	return line;
}


bool File::end() const{
	return inputFile->eof();
}

void File::Asign(std::string &cuerpo){
	cuerpo.assign((std::istreambuf_iterator<char>(*inputFile)),
		            std::istreambuf_iterator<char>());
}

int File::longitud_archivo(){
	inputFile->seekg (0, inputFile->end);
	int length = inputFile->tellg();
	inputFile->seekg (0, inputFile->beg);
	return length;
}


File::~File() {
    delete inputFile;
}



