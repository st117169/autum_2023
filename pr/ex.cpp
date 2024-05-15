#include "ex.h"

FileNotFoundException::FileNotFoundException() {}

FileNotFoundException::FileNotFoundException(const std::string& message) : message(message) {}

const char* FileNotFoundException::what() const noexcept {
    return this->message.c_str();
}