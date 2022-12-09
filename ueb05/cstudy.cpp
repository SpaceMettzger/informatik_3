#include "cstudy.hpp"
#include <string>
#include <iostream>

CStudy::CStudy (std::string study_name, bool has_nc, int num_semesters):
    m_study_name(study_name),
    m_has_nc(has_nc),
    m_num_semesters(num_semesters)
    {};

CStudy::CStudy() {}

CStudy::~CStudy()
{
    std::cout << "Studiengang " << m_study_name << " wird vernichtet" << std::endl;
}

void CStudy::print()
{
    std::cout << m_study_name;
}

std::string CStudy::get_name()
{
    return m_study_name;
}

void CStudy::load(std::ifstream& input, CBookings& bookings)
{
    std::string line;
    std::size_t start_pos, end_pos;
    int span;
    std::string sub_string;
    while (getline(input, line))
    {
        std::string search_string = "<name>";
        if(line.find(search_string))
        {
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</name>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_study_name = sub_string.c_str();
        }
        else if(line.find("<nc>"))
        {
            std::string search_string = "<nc>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</nc>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            if (sub_string == "false")
            {
                m_has_nc = false;
            }
            else{
                m_has_nc = true;
            }

        }
        else if(line.find("<nrofterms>"))
        {
            std::string search_string = "<nrofterms>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</nrofterms>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_num_semesters = stoi(sub_string);
        }
        else if (line.find("</study>"))
        {
            break;
        }
    }
}
