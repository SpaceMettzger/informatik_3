#include "cbookings.hpp"
#include "clist.hpp"

#include <string>
#include <fstream>

namespace
{

void printStudents(CList <CPerson*>& persons)
{
    std::cout << "Students:" << std::endl;
    for (const auto& person : persons)
    {
        if (dynamic_cast<CStudent*>(person) != nullptr)
        {
            //person->print();
            std::cout << *person << std::endl;
        }
    }
}

void printTeachers(
    CList <CPerson*>& persons)
{
    std::cout << "Teachers:" << std::endl;
    for (const auto& person : persons)
    {
        if (dynamic_cast<CTeacher*>(person) != nullptr)
        {
            std::cout << *person << std::endl;
        }
    }
}


} // namespace

CBookings::CBookings(std::string file)
{
    std::fstream inoutput;
    std::string line;
    std::ifstream file_input;
    file_input.open(file);

    while (std::getline(file_input, line))
    {
        if (line.find("<block>") != std::string::npos)
        {
            CBlock* block = new CBlock();
            block->load(file_input, *this);
            m_blocks.push_back(block);
        }
        else if (line.find("<room>") != std::string::npos)
        {
            CRoom* room = new CRoom();
            room->load(file_input, *this);
            m_rooms.push_back(room);
        }
        else if (line.find("<study>") != std::string::npos)
        {
            CStudy* study = new CStudy();
            study->load(file_input, *this);
            m_studies.push_back(study);
        }
        else if (line.find("<student>") != std::string::npos)
        {
            CStudent* student = new CStudent();
            student->load(file_input, *this);
            m_persons.push_back(student);
        }
        else if (line.find("<teacher>") != std::string::npos)
        {
            CTeacher* teacher = new CTeacher();
            teacher->load(file_input, *this);
            m_persons.push_back(teacher);
        }
        else if (line.find("<subject>") != std::string::npos)
        {
            CSubject* subject = new CSubject();
            subject->load(file_input, *this);
            m_subjects.push_back(subject);
        }
        else if (line.find("<booking>") != std::string::npos)
        {
            CBooking* booking = new CBooking();
            booking->load(file_input, *this);
            m_bookings.push_back(booking);
        }
        else if (line.find("<tutor>") != std::string::npos)
        {
            CTutor* tutor = new CTutor();
            tutor->load(file_input, *this);
            m_persons.push_back(tutor);
        }
    }
    std::cout << "Datei wurde erfolgreich eingelesen!" << std::endl << std::endl;
}

CBookings::~CBookings()
{
    int i;
    std::cout << "Bloeke freigeben..." << std::endl;
    int vec_len = m_blocks.size();
    for (i = 0; i < vec_len; i++)
    {
        delete m_blocks[i];
    }
    std::cout << "Bloeke freigeben ok." << std::endl;

    std::cout << "Raeume freigeben..." << std::endl;
    vec_len = m_rooms.size();
    for (i = 0; i < vec_len; i++)
    {
        delete m_rooms[i];
    }
    std::cout << "Raeume freigeben ok." << std::endl;

    vec_len = m_studies.size();
    std::cout << "Studiengaenge freigeben..." << std::endl;
    for (i = 0; i < vec_len; i++)
    {
        delete m_studies[i];
    }
    std::cout << "Studiengaenge freigeben ok." << std::endl;

    std::cout << "Personen freigeben..." << std::endl;
        for (auto& person : m_persons)
    {
        delete person;
    }

    std::cout << "Personen freigeben ok." << std::endl;

    vec_len = m_subjects.size();
    std::cout << "Faecher freigeben..." << std::endl;
    for (i = 0; i < vec_len; i++)
    {
        delete m_subjects[i];
    }
    std::cout << "Faecher freigeben ok." << std::endl;

    vec_len = m_bookings.size();
    std::cout << "Belegungen freigeben..." << std::endl;
    for (i = 0; i < vec_len; i++)
    {
        delete m_bookings[i];
    }
    std::cout << "Belegungen freigeben ok." << std::endl;
};


CStudy* CBookings::findStudy(std::string name)
{
    int vec_len = m_studies.size();
    for (int i = 0; i < vec_len; i++)
    {
        if (m_studies[i]->get_name() == name)
            return m_studies[i];
    }
    return nullptr;
}

CBlock* CBookings::findBlock(int id)
{
    int vec_len = m_blocks.size();
    for (int i = 0; i < vec_len; i++)
    {
        if (m_blocks[i]->get_id() == id)
            return m_blocks[i];
    }
    return nullptr;
    }

CRoom* CBookings::findRoom(std::string name)
{
    int vec_len = m_rooms.size();
    for (int i = 0; i < vec_len; i++)
    {
        if (m_rooms[i]->get_name() == name)
            return m_rooms[i];
    }
    return nullptr;
}

CSubject* CBookings::findSubject(std::string name)
{
    int vec_len = m_subjects.size();
    for (int i = 0; i < vec_len; i++)
    {
        if (m_subjects[i]->get_name() == name)
        {
            return m_subjects[i];
        }
        else {return m_subjects[0];};
    }
    return nullptr;
}

CBooking* CBookings::findBooking(int id)
{
    int vec_len = m_bookings.size();
    for (int i = 0; i < vec_len; i++)
    {
        if (m_bookings[i]->get_booking() == id)
            return m_bookings[i];
    }
    return nullptr;
}

CPerson* CBookings::findPerson(std::string name)
{
    for (const auto& person : m_persons)
    {
        if (person->get_name() == name)
        {
            return person;
        }
    }
    return nullptr;
}

void CBookings::printBookings()
{
    std::cout << "Belegungen:" << std::endl << std::endl;
    for (const auto& entry : m_bookings)
    {
        entry->print();
        std::cout << std::endl;
    }
}


void CBookings::printPersons()
{
    std::cout << "Personen:" << std::endl;
    for (const auto& person : m_persons)
    {
        std::cout << *person;
        std::cout << std::endl;
    }
}

void CBookings::operator()(OutputFormats oformat)
{
    switch (oformat)
    {
        case ofPersons:
            printPersons();
            std::cout << std::endl;
            return;
        case ofStudents:
            printStudents(m_persons);
            std::cout << std::endl;
            return;
        case ofTeachers:
            printTeachers(m_persons);
            std::cout << std::endl;
            return;
        case ofBookings:
        {
            std::cout << "Belegungen: " << std::endl;
            int len_m_bookings = m_bookings.size();
            for (int i= 0; i < len_m_bookings; i++)
            {
                m_bookings[i]->print();
                std::cout << std::endl << std::endl;
            }
            std::cout << std::endl;
        }
    }
}
