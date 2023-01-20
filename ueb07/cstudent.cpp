#include "cstudent.hpp"
#include "cbookings.hpp"
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

CStudent::CStudent() {}

CStudent::~CStudent()
{
    std::cout << "Student*in " << get_name() << " wird vernichtet" << std::endl;
}

void CStudent::set_mat_nr(unsigned int nr)
{
    m_mat_nr = nr;
}

void CStudent::set_fs(unsigned short fs)
{
    m_fs = fs;
}

void CStudent::set_credits(unsigned credits)
{
    m_credits = credits;
}

void CStudent::set_study(CStudy* study)
{
    m_study = study;
}

int CStudent::get_mat_nr()
{
    return m_mat_nr;
}

std::ostream& CStudent::print(std::ostream& ostr)
{
        std::string name = get_name();
        ostr << name << " (*";
        get_date().print();
        int id = get_id();
        ostr << "; ID " << id << "; MatNr. " << m_mat_nr << ")";
        return ostr;
}

std::ostream& operator<<(std::ostream& ostr, CStudent& student)
{
    return student.print(ostr);
}

void CStudent::load(std::ifstream& input, CBookings& bookings)
{
    std::string line;
    std::size_t start_pos, end_pos;
    int span;
    std::string sub_string;
    while (getline(input, line))
    {
        if(line.find("<name>") != std::string::npos)
        {
            std::string search_string = "<name>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</name>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            set_name(sub_string);
        }
        else if(line.find("<address>") != std::string::npos)
        {
            std::string street = "";
            std::string number = "";
            int zip = 0;
            std::string city = "";
            while (line.find("</address>") == std::string::npos)
            {
                getline(input, line);
                if(line.find("<street>") != std::string::npos)
                {
                    std::string search_string = "<street>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</street>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    street = sub_string;
                }
                else if(line.find("<housenr>") != std::string::npos)
                {
                    std::string search_string = "<housenr>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</housenr>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    number = sub_string;
                }
                else if(line.find("<zipcode>") != std::string::npos)
                {
                    std::string search_string = "<zipcode>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</zipcode>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    zip = stoi(sub_string);
                }
                else if(line.find("<city>") != std::string::npos)
                {
                    std::string search_string = "<city>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</city>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    city = sub_string;
                }
            }
            set_address(street, number, zip, city);
        }
        else if(line.find("<birthday>") != std::string::npos)
        {
            int day = 0;
            int month = 0;
            int year = 0;
            while (line.find("</birthday>") == std::string::npos)
            {
                getline(input, line);
                if(line.find("<day>") != std::string::npos)
                {
                    std::string search_string = "<day>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</day>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    day = stoi(sub_string);
                }
                else if(line.find("<month>") != std::string::npos)
                {
                    std::string search_string = "<month>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</month>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    month = stoi(sub_string);
                }
                else if(line.find("<year>") != std::string::npos)
                {
                    std::string search_string = "<year>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</year>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    year = stoi(sub_string);
                }
            }
            set_date(day, month, year);
        }
        else if(line.find("<matriculationnr>") != std::string::npos)
        {
            std::string search_string = "<matriculationnr>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</matriculationnr>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_mat_nr = stoi(sub_string);
        }
        else if(line.find("<term>") != std::string::npos)
        {
            std::string search_string = "<term>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</term>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_fs = stoi(sub_string);
        }
        else if(line.find("<credits>") != std::string::npos)
        {
            std::string search_string = "<credits>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</credits>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_credits = stoi(sub_string);
        }
        else if(line.find("<study>") != std::string::npos)
        {
            std::string search_string = "<study>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</study>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_study = bookings.findStudy(sub_string);
        }
        else if (line.find("</student>") != std::string::npos)
        {
        return;
        }
    }
}
