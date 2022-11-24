#ifndef CTEACHER_HPP
#define CTEACHER_HPP

#include "cperson.hpp"
#include <string>

class CTeacher: public CPerson {

public:
    CTeacher(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year, unsigned int m_pers_nr);
    void print();

private:
    unsigned int m_pers_nr;
};


#endif
