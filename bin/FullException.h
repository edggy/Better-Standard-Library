#pragma once

#include <stdexcept>

class FullException: public std::runtime_error {
    public:
        explicit FullException(const char* message): std::runtime_error(message), msg_(message) {}
        explicit FullException(const std::string& message): std::runtime_error(message), msg_(message) {}

        virtual ~FullException() noexcept {}

        virtual const char* what() const noexcept {
           return msg_.c_str();
        }
    protected:
        std::string msg_;
};
