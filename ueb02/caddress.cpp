#include "caddress.hpp"
#include <iostream>

CAddress::CAddress(const char* street, const char* house_number, int post_code, const char* city):
    m_street(street),
    m_number(house_number),
    m_zip(post_code),
    m_city(city)
    {}

void CAddress::print() {
    std::cout << m_street << " " << m_number << std::endl;
    std::cout << m_zip << " " << m_city << std::endl;
}
