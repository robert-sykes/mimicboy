#include <exception>
#include <string>

class InvalidOpcodeException : std::exception  {
public:
    explicit InvalidOpcodeException() = default;
};