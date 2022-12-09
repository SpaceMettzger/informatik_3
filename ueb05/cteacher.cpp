#include "cteacher.hpp"
#include <iostream>
#include <iomanip>
#include <string>


CTeacher::CTeacher(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year, unsigned int pers_nr):
    CPerson(name, street, number, zip, city, day, month, year),
    m_pers_nr(pers_nr)
    {};

CTeacher::~CTeacher()
{
    std::cout << "Lehrer*in " << get_name() << " wird vernichtet" << std::endl;
}

void CTeacher::print()
{
    std::cout << get_name() << " (" << m_pers_nr << ")";
};


void CTeacher::load(std::ifstream& input, CBookings& bookings) 
{
std::string line;
    std::size_t start_pos, end_pos;
    int span;
    std::string sub_string;
    while (getline(input, line)) 
    {
        while (not line.find("</teacher>"))
        {
            if(line.find("<name>"))
            { 
                start_pos = line.find("<name>");
                end_pos = line.find("</name>");
                span = end_pos - start_pos;
                sub_string = line.substr(start_pos, span);
                set_name(sub_string.c_str());
            }     
            if(line.find("<address>"))
            {   
                std::string street = "";
                std::string number = "";
                int zip = 0;
                std::string city = "";
                while (not line.find("</address>")) 
                {
                    getline(input, line);
                    if(line.find("<street>")) 
                    {
                        start_pos = line.find("<street>");
                        end_pos = line.find("</street>");
                        span = end_pos - start_pos;
                        sub_string = line.substr(start_pos, span);
                        street = sub_string;
                    }
                    if(line.find("<housenr>")) 
                    {
                        start_pos = line.find("<housenr>");
                        end_pos = line.find("</housenr>");
                        span = end_pos - start_pos;
                        sub_string = line.substr(start_pos, span);
                        number = sub_string;
                    }
                    if(line.find("<zipcode>")) 
                    {
                        start_pos = line.find("<zipcode>");
                        end_pos = line.find("</zipcode>");
                        span = end_pos - start_pos;
                        sub_string = line.substr(start_pos, span);
                        zip = stoi(sub_string);
                    }
                    if(line.find("<city>")) 
                    {
                        start_pos = line.find("<city>");
                        end_pos = line.find("</city>");
                        span = end_pos - start_pos;
                        sub_string = line.substr(start_pos, span);
                        city = sub_string;
                    }                    
                }
                set_address(street, number, zip, city);
            }         
            if(line.find("<birthday>"))
            {   
                int day = 0;
                int month = 0;
                int year = 0;
                while (not line.find("</birthday>")) 
                {
                    getline(input, line);
                    if(line.find("<day>")) 
                    {
                        start_pos = line.find("<day>");
                        end_pos = line.find("</day>");
                        span = end_pos - start_pos;
                        sub_string = line.substr(start_pos, span);
                        day = stoi(sub_string);
                    }
                    if(line.find("<month>")) 
                    {
                        start_pos = line.find("<month>");
                        end_pos = line.find("</month>");
                        span = end_pos - start_pos;
                        sub_string = line.substr(start_pos, span);
                        month = stoi(sub_string);
                    }
                    if(line.find("<year>")) 
                    {
                        start_pos = line.find("<year>");
                        end_pos = line.find("</year>");
                        span = end_pos - start_pos;
                        sub_string = line.substr(start_pos, span);
                        year = stoi(sub_string);
                    }      
                }
                set_date(day, month, year);
            }
            if(line.find("<personalnr>"))
            { 
                start_pos = line.find("<personalnr>");
                end_pos = line.find("</personalnr>");
                span = end_pos - start_pos;
                sub_string = line.substr(start_pos, span);
                m_pers_nr = stoi(sub_string);
            }
        }
    }
}
