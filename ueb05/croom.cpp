#include "croom.hpp"
#include <iostream>
#include <string>

CRoom::CRoom(const char* name, const char* building, short seats):
    m_name(name),
    m_building(building),
    m_seats(seats)
    {}

void CRoom::print() 
{
    std::cout << m_name << " (" << m_building << ")";
}

std::string CRoom::get_building() 
{
    return m_name;
}

std::string CRoom::get_name()
{
    return m_name;
}

void CRoom::load(std::ifstream& input, CBookings& bookings) 
{
    std::string line;
    std::size_t start_pos, end_pos;
    int span;
    std::string sub_string;
    while (getline(input, line)) 
    {
        while (not line.find("</room>"))
        {
            if(line.find("<name>"))
            {
                start_pos = line.find("<name>");
                end_pos = line.find("</name>");
                span = end_pos - start_pos;
                sub_string = line.substr(start_pos, span);
                m_name = sub_string.c_str();
            }        
            else if(line.find("<building>"))
            {
                start_pos = line.find("<building>");
                end_pos = line.find("</building>");
                span = end_pos - start_pos;
                sub_string = line.substr(start_pos, span);
                m_building = sub_string.c_str();
            }
            else if(line.find("<seats>"))
            {
                start_pos = line.find("<seats>");
                end_pos = line.find("</seats>");
                span = end_pos - start_pos;
                sub_string = line.substr(start_pos, span);
                m_seats = stoi(sub_string);
            }
        }
    }
}


