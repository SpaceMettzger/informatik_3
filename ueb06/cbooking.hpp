#ifndef CBOOKING_HPP
#define CBOOKING_HPP

#include "csubject.hpp"
#include "cstudent.hpp"
#include "cdate.hpp"
#include "ctime.hpp"
#include "cbookings.hpp"

class CStudent;
class CSubject;
class CTutor;

class CBooking
{
    inline static unsigned int booking_nr = 0;
    unsigned int m_booking_nr;
    CSubject* m_subject;
    CPerson* m_student;
    CDate m_booking_date;
    CTime m_booking_time;

    public:
    CBooking(CSubject* subject, CPerson* student, int booking_day, int booking_month, int booking_year, int booking_hour, int booking_minute, int booking_seconds);
    CBooking();
    ~CBooking();
    void print();
    int get_booking();
    void load(std::ifstream& input, CBookings& bookings);
};


#endif
