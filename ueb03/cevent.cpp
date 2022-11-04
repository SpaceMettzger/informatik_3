#include "croom.hpp"
#include "cperson.hpp"
#include "cblock.hpp"
#include "cevent.hpp"
#include <string>


CEvent::CEvent(std::string name, CPerson* teacher, CRoom* room, CBlock* block, CWeekday weekday, short period):
    m_name(name),
    m_block(block),
    m_room(room),
    m_teacher(teacher),
    m_weekday(weekday),
    m_period(period)
    {}

void CEvent::print() {

}
