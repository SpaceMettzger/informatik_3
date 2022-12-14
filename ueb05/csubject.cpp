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
        if(line.find("<name>") != std::string::npos)
        {
            std::string search_string = "<name>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</name>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_subject_name = sub_string;
        }
        else if(line.find("<subjectnr>") != std::string::npos)
        {
            std::string search_string = "<subjectnr>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</subjectnr>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_number = stoi(sub_string);
        }
        else if(line.find("<study>") != std::string::npos)
        {
            std::string search_string = "<study>";
            start_pos = line.find(search_string) + search_string.size();
            end_pos = line.find("</study>");
            span = end_pos - start_pos;
            sub_string = line.substr(start_pos, span);
            m_study_name = bookings.findStudy(sub_string);
        }
        else if(line.find("<event>") != std::string::npos)
        {
            std::string name;
            CPerson *teacher;
            CRoom *room;
            CBlock *block;
            CWeekday weekday;
            short period;
            while (line.find("</event>") == std::string::npos)
            {
                getline(input, line);
                if(line.find("<name>") != std::string::npos)
                {
                    std::string search_string = "<name>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</name>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    name = sub_string;
                }
                else if(line.find("<teacher>") != std::string::npos)
                {
                    std::string search_string = "<teacher>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</teacher>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    teacher = bookings.findTeacher(sub_string);
                }
                else if(line.find("<room>") != std::string::npos)
                {
                    std::string search_string = "<room>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</room>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    room = bookings.findRoom(sub_string);
                }
                else if(line.find("<block>") != std::string::npos)
                {
                    std::string search_string = "<block>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</block>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    block = bookings.findBlock(stoi(sub_string));
                }
                else if(line.find("<weekday>") != std::string::npos)
                {
                    std::string search_string = "<weekday>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</weekday>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    if(sub_string == "Mo") {weekday = Mo;}
                    else if(sub_string == "Di") {weekday = Di;}
                    else if(sub_string == "Mi") {weekday = Mi;}
                    else if(sub_string == "Do") {weekday = Do;}
                    else if(sub_string == "Fr") {weekday = Fr;}
                    else if(sub_string == "Sa") {weekday = Sa;}
                    else {weekday = So;}
                }
                else if(line.find("<period>") != std::string::npos)
                {
                    std::string search_string = "<period>";
                    start_pos = line.find(search_string) + search_string.size();
                    end_pos = line.find("</period>");
                    span = end_pos - start_pos;
                    sub_string = line.substr(start_pos, span);
                    period = stoi(sub_string);
                }
            }
            CEvent event = CEvent(name, teacher, room, block, weekday, period);
            addEvent(&event);
        }
        else if (line.find("</subject>") != std::string::npos)
            break;
    }
}


