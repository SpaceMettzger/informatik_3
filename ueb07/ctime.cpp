#include "ctime.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <math.h>


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

CTime CTime::operator+(short adtl_minutes)
{
    short end_hours = this->get_hours();
    float end_minutes = this->get_minutes();
    short end_seconds = this->get_seconds();

    if (adtl_minutes % 60 == 0)
    {
        end_hours += adtl_minutes / 60;
    }
    else
    {
        float adtl_hours = std::ceil(adtl_minutes / 60);
        end_hours += adtl_hours;
        float remaining_minutes = float(adtl_minutes) / 60 - adtl_hours;
        end_minutes = end_minutes + (remaining_minutes * 60);
        if (end_minutes >= 60)
        {
            end_minutes = end_minutes - 60;
            end_hours++;
        }
    }
    CTime end_time(end_hours, end_minutes, end_seconds);
    return end_time;
}
