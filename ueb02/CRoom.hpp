#ifndef CROOM_HPP
#define CROOM_HPP

class CRoom {

public:
    CRoom(char, char, short);
    void print();

private:
    char m_name, m_building;
    short m_seats;
};


#endif
