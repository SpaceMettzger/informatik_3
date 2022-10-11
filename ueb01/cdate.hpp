#ifndef CDATE_HPP
#define CDATE_HPP

class CDate {

public:
    CDate();
    CDate(int year, int month, int day);
    void print();

private:
    int m_year, m_month, m_day;

};

#endif