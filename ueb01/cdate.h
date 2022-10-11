#ifndef CDATE_H
#define CDATE_H

class CDate
{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    CDate();
    CDate(int year, int month, int day);
    void SetDate(int year, int month, int day);
    void print();
};

#endif