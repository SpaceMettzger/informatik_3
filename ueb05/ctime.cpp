#include "ctime.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>


CTime::CTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        m_hours = ltm->tm_hour;
        m_minutes = ltm->tm_min;
        m_seconds = ltm->tm_sec;
}

CTime::CTime(short hours, short minutes, short seconds):
    m_hours(hours),
    m_minutes(minutes),
    m_seconds(seconds)
    {}

int CTime::get_hours() {
    return m_hours;
}

int CTime::get_minutes() {
    return m_minutes;
}


int CTime::get_seconds() {
    return m_seconds;
}


void CTime::print() {
    char fl;
    fl = std::cout.fill('0');
    if (m_seconds == 0) {
        std::cout << std::setw(2) << m_hours << ":" << std::setw(2) << m_minutes;
    }
    else {
        std::cout << std::setw(2) << m_hours << ":" << std::setw(2) << m_minutes << ":" << std::setw(2) << m_seconds;
    }
    std::cout.fill(fl);

}

void CTime::set_time(short hours, short minutes, short seconds)
{
    m_hours = hours;
    m_minutes = minutes;
    m_seconds = seconds;
}
