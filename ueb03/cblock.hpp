#ifndef CBLOCK_HPP
#define CBLOCK_HPP

#include "ctime.hpp"

class CBlock {

public:
    CBlock(short, CTime);
    short getBlockNr();
    void print();
    CTime get_start_time();
    CTime get_end_time();

private:
    short m_block_id;
    CTime m_start_time, m_end_time;
    CTime getEnd(CTime);
};


#endif
