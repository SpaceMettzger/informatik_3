#include "cperson.hpp"
#include "caddress.hpp"
#include "cdate.hpp"
#include <iostream>


CPerson::CPerson(char name, CAddress address, CDate birth_date):
    m_name(name),
    m_address(address),
    m_birth_date(birth_date)
    {}

void CPerson::print() {
    short year, month, day = m_birth_date.get_date();
    std::cout << m_name << "(*" << year << "." << month << "." << day  << ")";
}

CAddress CPerson::getAddress() {
    return m_address;
}
