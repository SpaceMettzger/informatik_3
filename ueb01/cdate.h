#ifndef CDATE_H
#define CDATE_H

class CDate {

private:
    int m_year, m_month, m_day;

public:
    CDate();
    CDate(int year, int month, int day);
    void SetDate(int year, int month, int day);
    void print();
};

#endif