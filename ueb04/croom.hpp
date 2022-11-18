#ifndef CROOM_HPP
#define CROOM_HPP

#include <string>

class CRoom {

public:
    CRoom(const char*, const char*, short);
    void print();
    std::string get_building();

private:
    const char* m_name;
    const char* m_building;
    short m_seats;
};


#endif
