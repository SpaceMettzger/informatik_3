#ifndef CDATE_HPP
#define CDATE_HPP

class CDate {

public:
    CDate();
    CDate(short year, short month, short day);
    void print();
    short get_year();
    short get_month();
    short get_day();

private:
    short m_year, m_month, m_day;

};

#endif
