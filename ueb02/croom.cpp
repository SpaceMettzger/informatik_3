#include "croom.hpp"
#include <iostream>


CRoom::CRoom(char const* name, char const* building, short seats):
    m_name(*name),
    m_building(*building),
    m_seats(seats)
    {}

void CRoom::print() {
    std::cout << m_name << "(" << m_building << ")";
}
