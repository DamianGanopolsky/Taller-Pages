#ifndef COMMON_SRC_FILE_EXCEPTION_H_
#define COMMON_SRC_FILE_EXCEPTION_H_
#include <string>

class FileException: public std::exception {
private:
    std::string msg_;

public:
    //Cppcheck arroja un falso positivo, "the function what
    // is never used" pero en realidad si se usa, solo cuando
    //hay una excepcion, sirve para dar un mensaje acerca de lo que paso
    /*const char* what() const throw() {
    	return msg_.c_str();
    }*/

    explicit FileException(const std::string& message);
};

#endif /* COMMON_SRC_FILE_EXCEPTION_H_ */
