#include "cstudent.hpp"
#include <iostream>
#include <iomanip>
#include <string>


CStudent::CStudent(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year,
                    unsigned int mat_nr, unsigned short fs, unsigned credits, CStudy* study):
        CPerson(name, street, number, zip, city, day, month, year),
        m_mat_nr(mat_nr),
        m_fs(fs),
        m_credits(credits),
        m_study(study)
        {}

void CStudent::print()
{
        std::cout << get_name() << " (*";
        get_date().print();
        std::cout << "; MatNr. " << m_mat_nr << ")";
}
