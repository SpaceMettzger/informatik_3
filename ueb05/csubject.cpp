#include "csubject.hpp"
#include "cevent.hpp"
#include <iostream>

CSubject::CSubject(std::string subject_name, int number, CStudy* study_name):
    m_subject_name(subject_name),
    m_number(number),
    m_study_name(study_name)
    {}

CSubject::CSubject() {}

void CSubject::addEvent(CEvent* event)
{
    m_events.push_back(event);
}

CSubject::~CSubject()
{
    std::cout << "Studienfach Nr. " << m_subject_name << " wird vernichtet" << std::endl;
}

void CSubject::print()
{
    std::cout << "'" << m_subject_name << " (" << m_number << "; ";
    m_study_name->print();
    std::cout << ")'";
}

std::string CSubject::get_name()
{
    return m_subject_name;
}

void CSubject::load(std::ifstream& input, CBookings& bookings)
{
std::string line;
    std::size_t start_pos, end_pos;
    int span;
    std::string sub_string;
    while (getline(input, line))
    {
        if(line.find("<name>"))
        {
            start_pos = line.find("<name>");
            end_pos = line.find("</name>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_subject_name = sub_string;
        }
        else if(line.find("<subjectnr>"))
        {
            start_pos = line.find("<subjectnr>");
            end_pos = line.find("</subjectnr>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_number = stoi(sub_string);
        }
        else if(line.find("<study>"))
        {
            start_pos = line.find("<study>");
            end_pos = line.find("</study>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_study_name = bookings.findStudy(sub_string);
        }
        else if(line.find("<event>"))
        {
            std::string name;
            CPerson *teacher;
            CRoom *room;
            CBlock *block;
            CWeekday weekday;
            short period;
            while (not line.find("</event>"))
            {
                getline(input, line);
                if(line.find("<name>"))
                {
                    start_pos = line.find("<name>");
                    end_pos = line.find("</name>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    name = sub_string;
                }
                else if(line.find("<teacher>"))
                {
                    start_pos = line.find("<teacher>");
                    end_pos = line.find("</teacher>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    teacher = bookings.findTeacher(sub_string);
                }
                else if(line.find("<room>"))
                {
                    start_pos = line.find("<room>");
                    end_pos = line.find("</room>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    room = bookings.findRoom(sub_string);
                }
                else if(line.find("<block>"))
                {
                    start_pos = line.find("<block>");
                    end_pos = line.find("</block>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    block = bookings.findBlock(stoi(sub_string));
                }
                else if(line.find("<weekday>"))
                {
                    start_pos = line.find("<weekday>");
                    end_pos = line.find("</weekday>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    weekday = CWeekday(stoi(sub_string));
                }
                else if(line.find("<period>"))
                {
                    start_pos = line.find("<period>");
                    end_pos = line.find("</period>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    period = stoi(sub_string);
                }
            }
            CEvent event = CEvent(name, teacher, room, block, weekday, period);
            addEvent(&event);
        }
        else if (line.find("</subject>"))
            break;
    }
}
