#ifndef CBOOKINGS_HPP
#define CBOOKINGS_HPP

#include <vector>
#include "cblock.hpp"
#include "croom.hpp"
#include "csubject.hpp"
#include "cstudy.hpp"
#include "cbooking.hpp"
#include "cstudent.hpp"
#include "cteacher.hpp"

class CBlock;
class CStudy;
class CPerson;
class CRoom;
class CSubject;
class CBooking;
class CTeacher;

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
    CBookings(std::string file_name);
    CBlock* findBlock(int id);
    CRoom* findRoom(std::string name);
    CStudy* findStudy(std::string name);
    CSubject* findSubject(std::string name);
    CBooking* findBooking(int id);
    CStudent* findStudent(std::string name);
    CTeacher* findTeacher(std::string name);
    void print();

};


#endif
