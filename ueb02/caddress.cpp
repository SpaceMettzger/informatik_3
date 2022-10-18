#include "caddress.hpp"
#include <iostream>

CAddress::CAddress(char const *street, char const *house_number, int post_code, char const *city):
    m_street(*street),
    m_number(*house_number),
    m_zip(post_code),
    m_city(*city)
    {}

void CAddress::print() {
    std::cout << m_street << " " << m_number << std::endl;
    std::cout << m_zip << " " << m_city << std::endl;
}
