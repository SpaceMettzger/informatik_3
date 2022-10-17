#ifndef CPERSON_HPP
#define CPERSON_HPP

#include "caddress.hpp"
#include "cdate.hpp"

class CPerson {

public:
    CPerson(char, CAddress, CDate);
    void print();
    void getAddress();

private:
    char m_name;
    CAddress m_address;
    CDate m_birth_date;
};


#endif
