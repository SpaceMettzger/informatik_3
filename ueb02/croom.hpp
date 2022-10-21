#ifndef CROOM_HPP
#define CROOM_HPP

class CRoom {

public:
    CRoom(const char*, const char*, short);
    void print();

private:
    const char* m_name;
    const char* m_building;
    short m_seats;
};


#endif
