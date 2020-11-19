#ifndef COMMON_SRC_SOCKET_EXCEPTION_H_
#define COMMON_SRC_SOCKET_EXCEPTION_H_
#include <string>

class SocketException: public std::exception {
private:
    std::string msg_;

public:
    explicit SocketException(const std::string& message);

    const char* what() const throw() {
            return msg_.c_str();
    }
};


#endif /* COMMON_SRC_SOCKET_EXCEPTION_H_ */
