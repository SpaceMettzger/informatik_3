#ifndef CBLOCK_HPP
#define CBLOCK_HPP

#include "ctime.hpp"

class CBlock {

public:
    CBlock(short, CTime);
    CTime getEnd(CTime);
    short getBlockNr();
    void print();
    CTime m_start_time, m_end_time;

private:
    short m_block_id;
};


#endif
