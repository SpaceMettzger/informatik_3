#ifndef CTEACHER_HPP
#define CTEACHER_HPP

#include "cperson.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class CPerson;
class CBookings;

class CTeacher: virtual public CPerson {

public:
    CTeacher(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year, unsigned int m_pers_nr);
    CTeacher();
    ~CTeacher();
    void set_pers_nr(unsigned int);
    int get_pers_nr();
    virtual std::ostream& print(std::ostream& ostr);
    void load(std::ifstream& input, CBookings& bookings);
    friend std::ostream& operator<<(std::ostream& ostr, CTeacher& teacher);

private:
    unsigned int m_pers_nr;
};


#endif
