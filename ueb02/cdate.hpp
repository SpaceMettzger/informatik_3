#ifndef CDATE_HPP
#define CDATE_HPP

class CDate {

public:
    CDate();
    CDate(short year, short month, short day);
    void print();

private:
    short m_year, m_month, m_day;

};

#endif
