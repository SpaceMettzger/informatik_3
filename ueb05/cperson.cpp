#include "cperson.hpp"
#include "caddress.hpp"
#include "cdate.hpp"
#include <iostream>
#include <iomanip>
#include <string>


CPerson::CPerson(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year):
        m_name(name),
        m_address(street, number, zip, city),
        m_birth_date(day, month, year)
        {
            id ++;
            m_id = id;
        }

CPerson::~CPerson()
{
    std::cout << "Person " << m_name << " wird vernichtet" << std::endl;
}

void CPerson::print()
{
    short year = m_birth_date.get_year();
    short month = m_birth_date.get_month();
    short day = m_birth_date.get_day();
    char fl;
    fl = std::cout.fill('0');
    std::cout << m_name << " (*" << std::setw(2) << day << "." << std::setw(2) << month << "." << std::setw(4) << year  << ")";
    std::cout.fill(fl);
}

CAddress& CPerson::getAddress()
{
    return m_address;
}

std::string CPerson::get_name()
{
    return m_name;
}

CDate& CPerson::get_date()
{
    return m_birth_date;
}

void CPerson::set_name(std::string name) 
{
    m_name = name.c_str();
}

void CPerson::set_address(std::string street, std::string number, int zip, std::string city)
{
    m_address.set_address(street, number, zip, city);
}

void CPerson::set_date(int day, int month, int year)
{
    m_birth_date.set_date(day, month, year);
}
