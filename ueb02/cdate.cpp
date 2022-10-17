#include "cdate.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>


CDate::CDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    m_year = ltm->tm_year + 1900;
    m_month = ltm->tm_mon + 1;
    m_day = ltm->tm_mday;
 }

CDate::CDate(short day, short month, short year):
    m_year(year),
    m_month(month),
    m_day(day)
    {}

void CDate::print() {
    char fl;
    fl = std::cout.fill('0');
    std::cout << std::setw(2) << m_day << ":" << std::setw(2) << m_month << ":" << std::setw(2) << m_year;
    std::cout.fill(fl);
}
