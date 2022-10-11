#include <stdio.h>
#include <ctime>
#include "ctime.h"


class CTime {
    private:
    int m_hours, m_minutes, m_seconds;

    public:

    CTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        setTime(m_hours = ltm->tm_hour, m_minutes = ltm->tm_min, m_seconds = ltm->tm_sec);
    }

    CTime(int hours, int minutes, int seconds = 0) {
        setTime(m_hours = hours, m_minutes = minutes, m_seconds = seconds);
    }

    void setTime(int hours, int minutes, int seconds) {
        m_hours = hours;
        m_minutes = minutes;
        m_seconds = seconds;
    }

    void print() {
        printf("%2i.%2i.%2i", m_hours, m_minutes, m_seconds);
    }
};