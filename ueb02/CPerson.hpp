#ifndef CPERSON_HPP
#define CPERSON_HPP

#include "caddress.hpp"

class CPerson {

public:
    CPerson(char, CAddress, CDate);
    void print();

private:
    char m_name;
    CAddress m_address;
    CDate m_birthdate;
};


#endif
