#include <string>
#include "Socket_exception.h"


SocketException::SocketException(const std::string& message) : msg_(message) {
}
