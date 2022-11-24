#include "csubject.hpp"
#include <iostream>

CSubject::CSubject(std::string subject_name, int number, CStudy* study_name):
    m_subject_name(subject_name),
    m_number(number),
    m_study_name(study_name)
    {}

void CSubject::addEvent(CEvent* event)
{
    m_events.push_back(event);
}

void CSubject::print()
{
    std::cout << "'" << m_subject_name << " (" << m_number << "; ";
    m_study_name->print();
    std::cout << ")'";
}
