#ifndef COMMON_SRC_FILE_EXCEPTION_H_
#define COMMON_SRC_FILE_EXCEPTION_H_
#include <string>

class FileException: public std::exception {
private:
    std::string msg_;

public:
    const char* what() const throw() {
    	return msg_.c_str();
    }

    explicit FileException(const std::string& message);
};

#endif /* COMMON_SRC_FILE_EXCEPTION_H_ */
