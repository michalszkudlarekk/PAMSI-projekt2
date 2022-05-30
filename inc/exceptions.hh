#ifndef EXCEPTIONS_HH
#define EXCEPTIONS_HH

#include <iostream>

class exception /* Klasa odpowiedzalna za "wyłapywanie" błędów */
{
public:
    exception(const std::string &err)
        : errMsg(err) {}
    std::string getError() { return errMsg; }

private:
    std::string errMsg;
};

#endif