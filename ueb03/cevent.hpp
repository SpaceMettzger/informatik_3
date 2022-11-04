#ifndef CEVENT_HPP
#define CEVENT_HPP

#include <string>
#include "croom.hpp"
#include "cperson.hpp"
#include "cblock.hpp"


enum CWeekday { Mo = 1,
                Di = 2,
                Mi = 3,
                Do = 4,
                Fr = 5,
                Sa = 6,
                So = 7} ;

class CEvent {
    public:
    CEvent(std::string name, CPerson* teacher, CRoom* room, CBlock* block, CWeekday weekday, short period);
    void print();

    private:
    std::string m_name;
    CBlock *m_block;
    CRoom *m_room;
    CPerson *m_teacher;
    int m_weekday;
    short m_period;
};





#endif
