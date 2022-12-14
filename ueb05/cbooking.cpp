#include "cbooking.hpp"
#include <string>
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

CBooking::CBooking()
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
    std::cout << " belegt.";
}

int CBooking::get_booking()
{
    return m_booking_nr;
}


void CBooking::load(std::ifstream& input, CBookings& bookings)
{
    std::string line;
    std::size_t start_pos, end_pos;
    int span;
    std::string sub_string;
    while (getline(input, line))
    {
        if(line.find("<subject>") != std::string::npos)
        {
            std::string search_string = "<subject>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</subject>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_subject = bookings.findSubject(sub_string);
        }
        else if(line.find("<student>") != std::string::npos)
        {
            std::string search_string = "<student>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</student>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_student = bookings.findStudent(sub_string);
        }
        else if(line.find("<bookingdate>") != std::string::npos)
        {
            int day, month, year = 0;
            while (line.find("</bookingdate>") == std::string::npos)
            {
                getline(input, line);
                if(line.find("<day>") != std::string::npos)
                {
                    std::string search_string = "<day>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</day>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    day = stoi(sub_string);
                }
                else if(line.find("<month>") != std::string::npos)
                {
                    std::string search_string = "<month>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</month>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    month = stoi(sub_string);
                }
                else if(line.find("<year>") != std::string::npos)
                {
                    std::string search_string = "<year>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</year>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    year = stoi(sub_string);
                }
                m_booking_date.set_date(day, month, year);
            }
        }
        else if(line.find("<bookingtime>") != std::string::npos)
        {
            short hours, minutes, seconds = 0;
            while (line.find("</bookingtime>") == std::string::npos)
            {
                getline(input, line);
                if(line.find("<hour>") != std::string::npos)
                {
                    std::string search_string = "<hour>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</hour>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    hours = stoi(sub_string);
                }
                else if(line.find("<minute>") != std::string::npos)
                {
                    std::string search_string = "<minute>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</minute>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    minutes = stoi(sub_string);
                }
                else if(line.find("<second>") != std::string::npos)
                {
                    std::string search_string = "<second>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</second>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    seconds = stoi(sub_string);
                }
                m_booking_time.set_time(hours, minutes, seconds);
            }
        }
        if(line.find("</booking>") != std::string::npos)
            return;
    }
}
