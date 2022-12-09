#ifndef CBLOCK_HPP
#define CBLOCK_HPP

#include "ctime.hpp"
#include "cbookings.hpp"

#include <iostream>

class CBookings;

class CBlock {

public:
    CBlock(short, CTime);
    CBlock();
    short getBlockNr();
    void print();
    CTime get_start_time();
    CTime get_end_time();
    void load(std::ifstream& input, CBookings&);
    int get_id();

private:
    short m_block_id;
    CTime m_start_time, m_end_time;
    CTime getEnd(CTime);
};


#endif
