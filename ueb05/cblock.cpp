#include "cblock.hpp"
#include "ctime.hpp"
#include "cbookings.hpp"
#include <iostream>
#include <iomanip>
#include <string>


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

CTime CBlock::get_start_time() {
    return m_start_time;
}

CTime CBlock::get_end_time() {
    return m_end_time;
}

int CBlock::get_id()
{
    return m_block_id;
}

void CBlock::load(std::ifstream& input, CBookings& bookings) 
{
    std::string line;
    std::size_t start_pos, end_pos;
    int span;
    std::string sub_string;
    while (getline(input, line)) 
    {
        while (not line.find("</block>"))
        {
            if(line.find("<blocknr>"))
            {
                start_pos = line.find("<blocknr>");
                end_pos = line.find("</blocknr>");
                span = end_pos - start_pos;
                sub_string = line.substr(start_pos, span);
                m_block_id = stoi(sub_string);
            }        
            else if(line.find("<begin>"))
            {
                int start_hour, start_minute, start_second = 0;
                // check for <hour>, <minute> and <second>, convert each to int, passt to CTime start_time, m_start_time = CTime start_time,
                // pass start_time to get_end_time
                if (line.find("<hour>")) 
                {
                    start_pos = line.find("<hour>");
                    end_pos = line.find("</hour>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    start_hour = stoi(sub_string);
                }
                else if (line.find("<minute>")) 
                {
                    start_pos = line.find("<minute>");
                    end_pos = line.find("</minute>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    start_minute = stoi(sub_string);
                }
                else if (line.find("<second>")) 
                {
                    start_pos = line.find("<second>");
                    end_pos = line.find("</second>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    start_second = stoi(sub_string);
                }
                m_start_time = CTime(start_hour, start_minute, start_second);
                m_end_time = get_end_time();
            }
        }
    }
}
