#include <string>
#include "Socket_exception.h"


SocketException::SocketException(const std::string& message) : msg_(message) {
}

const char* SocketException::what() const noexcept {
    return msg_.c_str();
}
