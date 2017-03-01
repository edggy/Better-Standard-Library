#pragma once

#include <stdexcept>

class EmptyException: public std::runtime_error {
    public:
        explicit EmptyException(const char* message): std::runtime_error(message), msg_(message) {}
        explicit EmptyException(const std::string& message): std::runtime_error(message), msg_(message) {}

        virtual ~EmptyException() noexcept {}

        virtual const char* what() const noexcept {
           return msg_.c_str();
        }
    protected:
        std::string msg_;
};
