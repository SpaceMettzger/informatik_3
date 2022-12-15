#include "caddress.hpp"
#include <iostream>
#include <string>

CAddress::CAddress(const char* street, const char* house_number, unsigned int post_code, const char* city):
    m_street(street),
    m_number(house_number),
    m_zip(post_code),
    m_city(city)
    {}

CAddress::CAddress()
    {}

void CAddress::print()
{
    std::cout << m_street << " " << m_number << std::endl;
    std::cout << m_zip << " " << m_city;
}

void CAddress::set_address(std::string street, std::string number, int zip, std::string city)
{
    m_street = street.c_str();
    m_number = number.c_str();
    m_zip = zip;
    m_city = city.c_str();
}
