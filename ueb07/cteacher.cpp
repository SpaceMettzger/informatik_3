#include "cteacher.hpp"
#include "cbookings.hpp"
#include <iostream>
#include <iomanip>
#include <string>


CTeacher::CTeacher(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year, unsigned int pers_nr):
    CPerson(name, street, number, zip, city, day, month, year),
    m_pers_nr(pers_nr)
    {};

CTeacher::CTeacher() {}

CTeacher::~CTeacher()
{
    std::cout << "Lehrer*in " << get_name() << " wird vernichtet" << std::endl;
}

void CTeacher::set_pers_nr(unsigned int pers_nr)
{
    m_pers_nr = pers_nr;
}

int CTeacher::get_pers_nr()
{
    return m_pers_nr;
}


std::ostream& CTeacher::print(std::ostream& ostr)
{
        std::string name = get_name();
        ostr << name << " (*";
        get_date().print();
        int id = get_id();
        ostr << "; ID " << id  << "; PersNr. " << m_pers_nr << ")";
        return ostr;
};


std::ostream& operator<<(std::ostream& ostr, CTeacher& teacher)
{
    return teacher.print(ostr);
}

void CTeacher::load(std::ifstream& input, CBookings& bookings)
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
            set_name(sub_string.c_str());
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
        else if(line.find("<personalnr>") != std::string::npos)
        {
            std::string search_string = "<personalnr>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</personalnr>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_pers_nr = stoi(sub_string);
        }
        else if (line.find("</teacher>") != std::string::npos)
            break;
    }
}
