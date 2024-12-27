#include <exception>
#include <iostream>
#include <string>

class Exception_Attack_Out_Of_Bounds : public std::exception
{
    std::string _msg;
public:
    Exception_Attack_Out_Of_Bounds(std::string message) : _msg{ message } {}

    virtual const char* what() const noexcept override
    {
        return _msg.c_str();
    }
};
