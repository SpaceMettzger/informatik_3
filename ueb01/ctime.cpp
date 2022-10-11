#include "ctime.hpp"
#include <ctime>
#include <iostream>


CTime::CTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        m_hours = ltm->tm_hour; 
        m_minutes = ltm->tm_min; 
        m_seconds = ltm->tm_sec;
}

CTime::CTime(int hours, int minutes, int seconds):
    m_hours(hours),
    m_minutes(minutes),
    m_seconds(seconds) 
    {}

void CTime::print() {
    std::cout << m_hours << ":" << m_minutes << ":" << m_seconds;
}