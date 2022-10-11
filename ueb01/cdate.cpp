#include <stdio.h>
#include <ctime>
#include "cdate.h"


class CDate {
    private:
    int m_day, m_month, m_year;

    public:

    CDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        setDate(m_year = ltm->tm_year, m_month = ltm->tm_mon, m_day = ltm->tm_mday);
    }

    CDate(int year, int month, int day) {
        setDate(m_year = year, m_month = month, m_day = day);
    }

    void setDate(int year, int month, int day) {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    void print() {
        printf("%2i.%2i.%2i", m_day, m_month, m_year);
    }
};