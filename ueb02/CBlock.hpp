#ifndef CBLOCK_HPP
#define CBLOCK_HPP

#include "ctime.hpp"

class CBlock {

public:
    CBlock(short, CTime);
    CTime getEnd();
    short getBlockNr();
    void print();

private:
    short m_block_id;
    CTime m_start_time, m_end_time;
};


#endif
