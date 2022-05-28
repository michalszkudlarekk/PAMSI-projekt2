#ifndef EXCEPTIONS_HH
#define EXCEPTIONS_HH

#include <iostream>

class Exception /* Klasa odpowiedzalna za "łapanie" błędów */
{
public:
    Exception(const std::string &err)
        : errMsg(err) {}
    std::string getError() { return errMsg; }

private:
    std::string errMsg;
};

#endif