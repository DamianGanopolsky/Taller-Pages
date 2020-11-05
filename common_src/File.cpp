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


void File::rewind(){
	inputFile->clear();
	inputFile->seekg(0);
}


File::~File() {
    delete inputFile;
}



