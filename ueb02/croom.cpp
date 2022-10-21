#include "croom.hpp"
#include <iostream>


CRoom::CRoom(const char* name, const char* building, short seats):
    m_name(name),
    m_building(building),
    m_seats(seats)
    {}

void CRoom::print() {
    std::cout << m_name << " (" << m_building << ")";
}
