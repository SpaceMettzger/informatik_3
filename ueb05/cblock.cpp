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

CBlock::CBlock() {}

CBlock::~CBlock()
{
    std::cout << "Block Nr. " << m_block_id << " wird vernichtet" << std::endl;
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
        std::string search_string = "<blocknr>";
        if(line.find(search_string) != std::string::npos)
        {
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</blocknr>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_block_id = stoi(sub_string);
        }
        else if(line.find("<begin>") != std::string::npos)
        {
            int start_hour, start_minute, start_second = 0;
            std::string search_string = "<hour>";
            if (line.find(search_string) != std::string::npos)
            {
                start_pos = line.find(search_string) + search_string.size();
                end_pos = line.find("</hour>");
                span = end_pos - start_pos;
                sub_string = line.substr(start_pos, span);
                start_hour = stoi(sub_string);
            }
            else if (line.find("<minute>") != std::string::npos)
            {
                std::string search_string = "<minute>";
                start_pos = line.find(search_string) + search_string.size();
                end_pos = line.find("</minute>");
                span = end_pos - start_pos;
                sub_string = line.substr(start_pos, span);
                start_minute = stoi(sub_string);
            }
            else if (line.find("<second>") != std::string::npos)
            {
                std::string search_string = "<second>";
                start_pos = line.find(search_string) + search_string.size();
                end_pos = line.find("</second>");
                span = end_pos - start_pos;
                sub_string = line.substr(start_pos, span);
                start_second = stoi(sub_string);
            }
            m_start_time = CTime(start_hour, start_minute, start_second);
            m_end_time = get_end_time();
        }
        else if (line.find("</block>") != std::string::npos)
        {
            break;
        }
    }
}
