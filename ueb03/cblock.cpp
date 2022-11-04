#include "cblock.hpp"
#include "ctime.hpp"
#include <iostream>
#include <iomanip>


CBlock::CBlock(short block_id, CTime start_time):
    m_block_id(block_id),
    m_start_time(start_time)
    {
        m_end_time = getEnd(start_time);
    }


CTime CBlock::getEnd(CTime start_time) {
    int hours = start_time.get_hours();
    int minutes = start_time.get_minutes();
    int seconds = start_time.get_seconds();
    hours++;

    if (minutes == 30) {
        hours += 2;
        minutes = 0;
    }
    else if (minutes > 30) {
        minutes = 90 - minutes;
        hours++;
    }
    else {
        minutes = minutes + 30;
    }
    CTime end_time(hours, minutes, seconds);
    return end_time;
}


short CBlock::getBlockNr() {
    return m_block_id;
}


void CBlock::print() {
    char fl;
    fl = std::cout.fill('0');
    short hours = m_start_time.get_hours();
    short minutes = m_start_time.get_minutes();
    short end_hours = m_end_time.get_hours();
    short end_minutes = m_end_time.get_minutes();
    std::cout << std::setw(2) << hours << ":" << std::setw(2) << minutes << " - "  << std::setw(2) << end_hours << ":" << std::setw(2) << end_minutes;
    std::cout.fill(fl);
}
