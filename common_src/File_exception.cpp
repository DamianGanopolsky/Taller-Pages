#include <string>
#include "File_exception.h"


FileException::FileException(const std::string& message) : msg_(message) {
}

const char* FileException::what() const noexcept {
    return msg_.c_str();
}
