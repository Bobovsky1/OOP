#include <exception>
#include <iostream>
#include <string>

class Exception_Ship_Wreck : public std::exception
{
    std::string _msg;
public:
    Exception_Ship_Wreck(std::string message) : _msg{ message } {}

    virtual const char* what() const noexcept override
    {
        return _msg.c_str();
    }
};
