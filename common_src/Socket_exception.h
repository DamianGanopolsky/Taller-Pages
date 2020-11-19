#ifndef COMMON_SRC_SOCKET_EXCEPTION_H_
#define COMMON_SRC_SOCKET_EXCEPTION_H_
#include <string>

class SocketException: public std::exception {
private:
    std::string msg_;

public:
    /*const char* what() const throw() {
            return msg_.c_str();
    }*/

    explicit SocketException(const std::string& message);
};


#endif /* COMMON_SRC_SOCKET_EXCEPTION_H_ */
