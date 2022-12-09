#include "cbookings.hpp"

#include <string>
#include <fstream>

CBookings::CBookings(std::string file)
{
    std::fstream inoutput;
    std::string line;
    std::ifstream file_input;
    file_input.open(file);

    while (getline(file_input, line))
    {
        if (line.find("<block>")) 
        {
            CBlock* block = new CBlock();
            block->load(file_input, *this);
            m_blocks.push_back(block);
        }
        else if (line.find("<room>")) 
        {
            CRoom* room = new CRoom();
            room->load(file_input, *this);
            m_rooms.push_back(room);
        }
        else if (line.find("<study>")) 
        {
            CStudy* study = new CStudy();
            study->load(file_input, *this);
            m_studies.push_back(study);
        }
        else if (line.find("<student>")) 
        {
            CStudent* student = new CStudent();
            student->load(file_input, *this);
            m_students.push_back(student);
        }
        else if (line.find("<teacher>")) 
        {
            CTeacher* teacher = new CTeacher();
            teacher->load(file_input, *this);
            m_teachers.push_back(teacher);
        }
        else if (line.find("<subject>")) 
        {
            CSubject* subject = new CSubject();
            subject->load(file_input, *this);
            m_subjects.push_back(subject);
        }
        else if (line.find("<booking>")) 
        {
            CBooking* booking = new CBooking();
            booking->load(file_input, *this);
            m_bookings.push_back(booking);
        }
    }
}

CStudy* CBookings::findStudy(std::string name)
{
    int vec_len = m_studies.size();
    for (int i = 0; vec_len; i++)
    {
        if (m_studies[i]->get_name() == name)
            return m_studies[i];
    }
}

CBlock* CBookings::findBlock(int id)
{
    int vec_len = m_blocks.size();
    for (int i = 0; vec_len; i++)
    {
        if (m_blocks[i]->get_id() == id)
            return m_blocks[i];
    }
}
CRoom* CBookings::findRoom(std::string name) 
{
    int vec_len = m_rooms.size();
    for (int i = 0; vec_len; i++)
    {
        if (m_rooms[i]->get_name() == name)
            return m_rooms[i];
    }
}
CSubject* CBookings::findSubject(std::string name)
{
    int vec_len = m_subjects.size();
    for (int i = 0; vec_len; i++)
    {
        if (m_subjects[i]->get_name() == name)
            return m_subjects[i];
    }    
}
CBooking* CBookings::findBooking(int id)
{
    int vec_len = m_bookings.size();
    for (int i = 0; vec_len; i++)
    {
        if (m_bookings[i]->get_booking() == id)
            return m_bookings[i];
    }    
}
CStudent* CBookings::findStudent(std::string name)
{
    int vec_len = m_students.size();
    for (int i = 0; vec_len; i++)
    {
        if (m_students[i]->get_name() == name)
            return m_students[i];
    }        
}
CTeacher* CBookings::findTeacher(std::string name)
{
    int vec_len = m_teachers.size();
    for (int i = 0; vec_len; i++)
    {
        if (m_teachers[i]->get_name() == name)
            return m_teachers[i];
    }      
}