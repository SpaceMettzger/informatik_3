#ifndef CSTUDY_HPP
#define CSTUDY_HPP

#include <string>
#include <fstream>

#include "cbookings.hpp"

class CStudy
{
    std::string m_study_name;
    bool m_has_nc;
    int m_num_semesters;

    public:
    CStudy(std::string study_name, bool has_nc, int num_semesters);
    CStudy();
    ~CStudy();
    void print();
    void load(std::ifstream& input, CBookings& bookings);
    std::string get_name();
};

#endif
