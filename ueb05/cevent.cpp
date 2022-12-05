#include "croom.hpp"
#include "cperson.hpp"
#include "cblock.hpp"
#include "cevent.hpp"
#include "ctime.hpp"
#include <string>
#include <iostream>
#include <iomanip>


CEvent::CEvent(
        std::string name,
        CPerson* teacher,
        CRoom* room,
        CBlock* block,
        CWeekday weekday,
        short period):
    m_name(name),
    m_teacher(teacher),
    m_room(room),
    m_block(block),
    m_weekday(weekday),
    m_period(period)
{}

void CEvent::print()
{
    using std::cout;
    using std::string;
    using std::setw;
    string day;

    switch (m_weekday)
    {
        case Mo:
            day = "Montag";
            break;
        case Di:
            day = "Dienstag";
            break;
        case Mi:
            day = "Mittwoch";
            break;
        case Do:
            day = "Donnerstag";
            break;
        case Fr:
            day = "Freitag";
            break;
        case Sa:
            day = "Samstag";
            break;
        case So:
            day = "Sonntag";
            break;
    }
    cout << std::left << setw(12) << day
         << std::right;
    m_block->print();
    cout << "   " << setw(12) << m_name << "  "
         << m_teacher->get_name() << "  " << m_room->get_building();
}
