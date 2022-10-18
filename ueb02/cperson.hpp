#ifndef CPERSON_HPP
#define CPERSON_HPP

#include "caddress.hpp"
#include "cdate.hpp"

class CPerson {

public:
    CPerson(char const *, char const *, char const *, short, char const *, short, short, short);
    void print();
    CAddress getAddress();

private:
    char m_name;
    CAddress m_address;
    CDate m_birth_date;
};


#endif
