
#ifndef COMMON_SRC_SOCKET_READ_EXCEPTION_H_
#define COMMON_SRC_SOCKET_READ_EXCEPTION_H_

#include <string>

class Socket_Read_Exception: public std::exception {
private:
    std::string msg_;

public:
    explicit Socket_Read_Exception(const std::string& message);
};



#endif /* COMMON_SRC_SOCKET_READ_EXCEPTION_H_ */
