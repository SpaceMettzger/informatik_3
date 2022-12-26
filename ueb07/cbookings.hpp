#ifndef CBOOKINGS_HPP
#define CBOOKINGS_HPP

#include <vector>
#include "clist.hpp"
#include "cblock.hpp"
#include "croom.hpp"
#include "csubject.hpp"
#include "cstudy.hpp"
#include "cbooking.hpp"
#include "cstudent.hpp"
#include "cteacher.hpp"
#include "ctutor.hpp"

class CBlock;
class CStudy;
class CPerson;
class CRoom;
class CStudent;
class CSubject;
class CBooking;
class CTeacher;
class CTutor;

enum OutputFormats
{
    ofPersons = 1,
    ofStudents = 2,
    ofTeachers = 3,
    ofBookings = 4,
};

class CBookings
{
    std::vector <CBlock*> m_blocks;
    std::vector <CRoom*> m_rooms;
    std::vector <CStudy*> m_studies;
    std::vector <CSubject*> m_subjects;
    std::vector <CBooking*> m_bookings;
    CList <CPerson*> m_persons;


public:
    CBookings(std::string file_name);
    ~CBookings();
    void operator()(OutputFormats);
    CBlock* findBlock(int id);
    CRoom* findRoom(std::string name);
    CStudy* findStudy(std::string name);
    CSubject* findSubject(std::string name);
    CBooking* findBooking(int id);
    CStudent* findStudent(std::string name);
    CTeacher* findTeacher(std::string name);
    CPerson* findPerson(std::string name);
    void printBookings();
    void printPersons();
};


#endif
