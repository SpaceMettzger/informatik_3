#include "cteacher.hpp"
#include <iostream>

CTeacher::CTeacher(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year, unsigned int pers_nr):
    CPerson(name, street, number, zip, city, day, month, year),
    m_pers_nr(pers_nr)
    {};

CTeacher::~CTeacher()
{
    std::cout << "Lehrer*in " << get_name() << " wird vernichtet" << std::endl;
}

void CTeacher::print()
{
    std::cout << get_name() << " (" << m_pers_nr << ")";
};
