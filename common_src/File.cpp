#include "File.h"
#include <string>

bool File::end() const{
	return inputFile->eof();
}

void File::Assign(std::string &cuerpo){
	cuerpo.assign((std::istreambuf_iterator<char>(*inputFile)),
		            std::istreambuf_iterator<char>());
}


File::~File() {
    delete inputFile;
}



