#include "cbooking.hpp"
#include <iomanip>

CBooking::CBooking(CSubject* subject, CStudent* student, int booking_day, int booking_month, int booking_year, int booking_hour, int booking_minute, int booking_seconds):
    m_subject(subject),
    m_student(student),
    m_booking_date(booking_day, booking_month, booking_year),
    m_booking_time(booking_hour, booking_minute, booking_seconds)
    {
    booking_nr ++;
    this->m_booking_nr = booking_nr;
    }

CBooking::~CBooking()
{
    std::cout << "Belegung Nr. " << m_booking_nr << " wird vernichtet" << std::endl;
}

void CBooking::print()
{
    std::cout << "Belegung Nr. " << m_booking_nr << ":" << std::endl;
    std::cout << "Am ";
    m_booking_date.print();
    std::cout << " um ";
    m_booking_time.print();
    std::cout << std::endl;
    std::cout << "hat ";
    m_student->print();
    std::cout << std::endl;
    std::cout << "das Fach ";
    m_subject->print();
    std::cout << " belegt";
}
