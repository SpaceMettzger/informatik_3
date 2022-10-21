#ifndef CPERSON_HPP
#define CPERSON_HPP

#include "caddress.hpp"
#include "cdate.hpp"

class CPerson {

public:
    CPerson(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year):
        m_name(name),
        m_address(street, number, zip, city),
        m_birth_date(day, month, year)
        {}
    void print();
    CAddress getAddress();

private:
    const char* m_name;
    CAddress m_address;
    CDate m_birth_date;
};


#endif
