#ifndef CSTUDENT_HPP
#define CSTUDENT_HPP

#include "cperson.hpp"
#include "cstudy.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class CStudent: public CPerson 
{
public:
    CStudent(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year, 
                    unsigned int mat_nr, unsigned short fs, unsigned credits, CStudy* study);
    void print();

private:
    unsigned int m_mat_nr;
    unsigned short m_fs;
    unsigned m_credits;
    CStudy* m_study;
};


#endif
