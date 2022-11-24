#include "cbooking.hpp"

CBooking::CBooking(unsigned int booking_nr, CSubject* subject, CStudent* student, CDate booking_date, CTime booking_time):
    m_subject(subject),
    m_student(student),
    m_booking_date(booking_date),
    m_booking_time(booking_time)
    { 
    booking_nr ++;
    m_booking_nr = booking_nr;
    }

void CBooking::print()
{
    
}