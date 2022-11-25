#ifndef CBOOKING.HPP
#define CBOOKING.HPP

#include "csubject.hpp"
#include "cstudent.hpp"
#include "cdate.hpp"
#include "ctime.hpp"

class CBooking
{
    inline static unsigned int booking_nr = 0;
    unsigned int m_booking_nr;
    CSubject* m_subject;
    CStudent* m_student;
    CDate m_booking_date;
    CTime m_booking_time;

    public:
    CBooking(CSubject* subject, CStudent* student, int booking_day, int booking_month, int booking_year, int booking_hour, int booking_minute, int booking_seconds);
    ~CBooking();
    void print();
};


#endif
