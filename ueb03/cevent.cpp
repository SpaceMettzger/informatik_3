#include "croom.hpp"
#include "cperson.hpp"
#include "cblock.hpp"
#include "cevent.hpp"
#include "ctime.hpp"
#include <string>
#include <iostream>
#include <iomanip>


CEvent::CEvent(std::string name, CPerson* teacher, CRoom* room, CBlock* block, CWeekday weekday, short period):
    m_name(name),
    m_block(block),
    m_room(room),
    m_teacher(teacher),
    m_weekday(weekday),
    m_period(period)
    {}

void CEvent::print() {
    using std::cout;
    using std::string;
    using std::setw;
    string day;
    switch(m_weekday){
        case 1:
            day = "Montag";
            break;
        case 2:
            day = "Dienstag";
            break;
        case 3:
            day = "Mittwoch";
            break;
        case 4:
            day = "Donnerstag";
            break;
        case 5:
            day = "Freitag";
            break;
        case 6:
            day = "Samstag";
            break;
        case 7:
            day = "Sonntag";
            break;
    }
    short block_start_hours = m_block->get_start_time().get_hours();
    short block_start_minutes = m_block->get_start_time().get_minutes();
    short block_end_hours = m_block->get_end_time().get_hours();
    short block_end_minutes = m_block->get_end_time().get_minutes();
    char tmp;
    cout << std::left << setw(12) << day;
    tmp = cout.fill('0');
    cout << std::right << setw(2) << block_start_hours << ":" << setw(2) << block_start_minutes << " - " << setw(2) << block_end_hours << ":" << setw(2) << block_end_minutes;
    cout.fill(tmp);
    cout << "   " << setw(12) << m_name << "  " << m_teacher->get_name() << "  " << m_room->get_building() << std::endl;
    //m_block->print()
}
