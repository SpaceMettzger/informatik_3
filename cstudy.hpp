#ifndef CSTUDY_HPP
#define CSTUDY_HPP

#include <string>

class CStudy
{
    std::string m_study_name;
    bool m_has_nc; 
    int m_num_semesters;

    public:
    CStudy(std::string study_name, bool has_nc, int num_semesters);
    void print();
};

#endif
