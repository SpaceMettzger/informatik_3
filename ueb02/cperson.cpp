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
    std::cout << m_name << "(*" << m_birth_date.print() << ")";
}

void CPerson::getAddress() {
    return m_address;
}
