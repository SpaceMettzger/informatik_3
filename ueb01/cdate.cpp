#include <stdio.h>
#include "cdate.h"


class CDate {
    private:
    int m_day, m_month, m_year;

    public:
    CDate(int year, int month, int day) {
        setDate(year, month, day);
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