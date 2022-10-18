#include "cperson.hpp"
#include "caddress.hpp"
#include "cdate.hpp"
#include <iostream>


CPerson::CPerson(char const *name, char const *street, char const *number, short zip, char const *city, short year, short month, short day):
    m_name(*name),
    m_address(street, number, zip, city),
    m_birth_date(year, month, day)
    {}

void CPerson::print() {
    short year, month, day = m_birth_date.get_date();
    std::cout << m_name << "(*" << year << "." << month << "." << day  << ")";
}

CAddress CPerson::getAddress() {
    return m_address;
}
