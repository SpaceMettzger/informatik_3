#include "cdate.hpp"
#include <iostream>
#include <ctime>


CDate::CDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    m_year = ltm->tm_year + 1900;
    m_month = ltm->tm_mon + 1;
    m_day = ltm->tm_mday;
 }

CDate::CDate(int day, int month, int year):
    m_year(year),
    m_month(month),
    m_day(day)
    {}

void CDate::print() {
    std::cout << m_day << ":" << m_month << ":" << m_year;
}
