#ifndef CBOOKING.HPP
#define CBOOKING.HPP

#include "csubject.hpp"
#include "cstudent.hpp"
#include "cdate.hpp"
#include "ctime.hpp"

class CBooking
{
    static unsigned int booking_nr;
    unsigned int m_booking_nr;
    CSubject* m_subject;
    CStudent* m_student;
    CDate m_booking_date;
    CTime m_booking_time; 

    public:
    CBooking(unsigned int booking_nr, CSubject* subject, CStudent* student, CDate booking_date, CTime booking_time);
    void print();
};



#endif