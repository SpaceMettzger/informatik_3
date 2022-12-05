#ifndef CBOOKINGS.HPP
#define CBOOKINGS.HPP

#include "cblock.hpp"
#include "croom.hpp"
#include "csubject.hpp"
#include "cstudy.hpp"
#include "cbooking.hpp"
#include "cstudent.hpp"
#include "cteacher.hpp"

class CBookings
{
    std::vector <CBlock*> m_blocks;
    std::vector <CRoom*> m_rooms;
    std::vector <CStudy*> m_studies;
    std::vector <CSubject*> m_subjects;
    std::vector <CBooking*> m_bookings;
    std::vector <CStudent*> m_students;
    std::vector <CTeacher*> m_teachers;

    public:
    CBookings(std::string);
    CBlock* findBlock(std::string);
    CRoom* findRoom(std::string);
    CStudy* findStudy(std::string);
    CSubject* findSubject(std::string);
    CBooking* findBooking(std::string);
    CStudent* findStudent(std::string);
    CTeacher* findTeacher(std::string);

};


#endif
