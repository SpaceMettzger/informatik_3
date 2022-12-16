#ifndef CEVENT_HPP
#define CEVENT_HPP

#include "croom.hpp"
#include "cperson.hpp"
#include "cblock.hpp"

#include <string>

class CBlock;
class CRoom;


enum CWeekday
{
    Mo = 1,
    Di = 2,
    Mi = 3,
    Do = 4,
    Fr = 5,
    Sa = 6,
    So = 7
};


class CEvent
{
public:
    CEvent(std::string name, CPerson* teacher, CRoom* room, CBlock* block, CWeekday weekday, short period);
    CEvent();
    void print();
    void set_event(std::string name, CPerson* teacher, CRoom* room, CBlock* block, CWeekday weekday, short period);

private:
    std::string m_name;
    CPerson *m_teacher;
    CRoom *m_room;
    CBlock *m_block;
    int m_weekday;
    short m_period;
};

#endif
