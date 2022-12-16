#ifndef CTUTOR_HPP
#define CTUTOR_HPP

#include "cstudent.hpp"
#include "cteacher.hpp"
#include "cbookings.hpp"
#include <string>
#include <iostream>
#include <iomanip>



class CTutor: public CStudent, public CTeacher
{
public:
    CTutor(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year, unsigned int mat_nr, unsigned short fs, unsigned credits, CStudy* study, unsigned int pers_nr, unsigned int num_semesters_working);
    CTutor();
    ~CTutor();
    void print();
    void load(std::ifstream& input, CBookings& bookings);

private:
    unsigned int m_num_semesters_working;
};


#endif
