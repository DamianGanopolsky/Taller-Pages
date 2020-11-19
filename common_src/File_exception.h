#ifndef COMMON_SRC_FILE_EXCEPTION_H_
#define COMMON_SRC_FILE_EXCEPTION_H_
#include <string>

class FileException: public std::exception {
private:
    std::string msg_;

public:
    explicit FileException(const std::string& message);

    virtual const char* what() const noexcept;
};

#endif /* COMMON_SRC_FILE_EXCEPTION_H_ */
