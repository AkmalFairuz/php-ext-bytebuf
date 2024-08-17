#ifndef LIB_BUFFEREXCEPTION_H_
#define LIB_BUFFEREXCEPTION_H_

#include <stdexcept>

class ByteBufException final : public std::runtime_error {
public:
    explicit ByteBufException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif //LIB_BUFFEREXCEPTION_H_