#include "cblock.hpp"
#include "ctime.hpp"
#include <iostream>


CBlock::CBlock(short block_id, CTime start_time):
    m_block_id(block_id),
    m_start_time(start_time)
    {
        m_end_time = getEnd(start_time);
    }


CTime CBlock::getEnd(CTime start_time) {
    int hours, minutes, seconds = start_time.get_time();
    hours++;

    if (minutes > 30) {
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
    short hours, minutes, seconds = m_start_time.get_time();
    std::cout << "(" << hours << ":" << minutes << " - "  << hours << ":" << minutes << ")";
}