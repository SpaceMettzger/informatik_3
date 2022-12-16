#include "cevents.hpp"
#include "cevent.hpp"
#include <iostream>
#include <vector>

CEvents::CEvents() {};

void CEvents::addEvent(CEvent *event)
{
    m_events.push_back(event);
}

void CEvents::print()
{
    int counter = 1;
    for(CEvent* event: m_events)
    {
        std::cout << counter << ":  ";
        counter ++;
        event->print();
        std::cout << std::endl;
    }
}
