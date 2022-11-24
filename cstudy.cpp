#include "cstudy.hpp"
#include <string>
#include <iostream>

CStudy::CStudy (std::string study_name, bool has_nc, int num_semesters):
    m_study_name(study_name),
    m_has_nc(has_nc),
    m_num_semesters(num_semesters)
    {};

void CStudy::print()
{
    std::cout << m_study_name;

}