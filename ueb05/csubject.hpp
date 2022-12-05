#ifndef CSUBJECT_HPP
#define CSUBJECT_HPP

#include "cstudy.hpp"
#include "cevent.hpp"
#include <string>
#include <vector>

class CSubject
{
    std::string m_subject_name;
    int m_number;
    CStudy* m_study_name;
    std::vector <CEvent*> m_events;

    public:
    CSubject(std::string subject_name, int number, CStudy* study_name);
    ~CSubject();
    void addEvent(CEvent* event);
    void print();
};


#endif
