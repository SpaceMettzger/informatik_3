#ifndef CROOM_HPP
#define CROOM_HPP

#include <string>
#include <fstream>

#include "cbookings.hpp"

class CBookings;

class CRoom {

public:
    CRoom(std::string, const char*, short);
    CRoom();
    ~CRoom();
    void print();
    std::string get_building();
    void load(std::ifstream&, CBookings& bookings);
    std::string get_name();

private:
    std::string m_name;
    const char* m_building;
    short m_seats;
};


#endif
