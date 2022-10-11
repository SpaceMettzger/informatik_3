#ifndef CTIME_H
#define CTIME_H

class CTime{
    private:
        int m_hours, m_minutes, m_seconds;
    public:
        CTime();
        CTime(int hours, int minutes, int seconds);
        void setTime(int hours, int minutes, int seconds);
        void print();
};


#endif