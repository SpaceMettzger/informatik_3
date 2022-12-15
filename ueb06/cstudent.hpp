#ifndef CSTUDENT_HPP
#define CSTUDENT_HPP

#include "cperson.hpp"
#include "cstudy.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class CStudy;

class CStudent: virtual public CPerson
{
public:
    CStudent(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year,
                    unsigned int mat_nr, unsigned short fs, unsigned credits, CStudy* study);
    CStudent();
    ~CStudent();
    void print();
    void set_mat_nr(unsigned int);
    void set_fs(unsigned short);
    void set_credits(unsigned);
    void set_study(CStudy* study);
    void load(std::ifstream& input, CBookings& bookings);

private:
    unsigned int m_mat_nr;
    unsigned short m_fs;
    unsigned m_credits;
    CStudy* m_study;
};


#endif
