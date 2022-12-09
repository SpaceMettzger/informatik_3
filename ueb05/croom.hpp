#ifndef CROOM_HPP
#define CROOM_HPP

#include <string>
#include <fstream>

#include "cbookings.hpp"

class CRoom {

public:
    CRoom(const char*, const char*, short);
    CRoom();
    void print();
    std::string get_building();
    void load(std::ifstream& input, CBookings& bookings);
    std::string get_name();

private:
    const char* m_name;
    const char* m_building;
    short m_seats;
};


#endif
