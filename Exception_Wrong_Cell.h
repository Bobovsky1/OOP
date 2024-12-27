#include <exception>
#include <iostream>
#include <string>

class Exception_Wrong_Cell : public std::exception
{
    std::string _msg;
public:
    Exception_Wrong_Cell(std::string message) : _msg{ message } {}

    virtual const char* what() const noexcept override
    {
        return _msg.c_str();
    }
};

