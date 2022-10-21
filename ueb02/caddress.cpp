#include "caddress.hpp"
#include <iostream>

CAddress::CAddress(const char* street, const char* house_number, int post_code, const char* city)
    {}

void CAddress::print() {
    std::cout << m_street << " " << m_number << std::endl;
    std::cout << m_zip << " " << m_city << std::endl;
}
