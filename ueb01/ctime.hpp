#ifndef CTIME_HPP
#define CTIME_HPP

class CTime {

public:
    CTime();
    CTime(short hours, short minutes, short seconds = 0);
    void print();

private:
    short m_hours, m_minutes, m_seconds;
};


#endif
