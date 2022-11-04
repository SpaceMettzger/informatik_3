#ifndef CEVENTS_HPP
#define CEVENTS_HPP

#include <vector>
#include "cevent.hpp"

class CEvents {
    public:
    CEvents();
    void addEvent(CEvent *event);
    void print();


    private:
    vector <CEvent*> m_events;

}


#endif
