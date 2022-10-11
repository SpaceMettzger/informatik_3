#ifndef CTIME_HPP
#define CTIME_HPP

class CTime {

public:
    CTime();
    CTime(int hours, int minutes, int seconds = 0);
    void print();

private:
    int m_hours, m_minutes, m_seconds;
};


#endif