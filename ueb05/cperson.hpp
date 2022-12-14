#ifndef CPERSON_HPP
#define CPERSON_HPP

#include "caddress.hpp"
#include "cdate.hpp"
#include <string>

class CPerson {

public:
    CPerson(std::string name, const char* street, const char* number, short zip, const char* city, short day, short month, short year);
    CPerson();
    virtual ~CPerson();
    void print();
    CAddress& getAddress();
    std::string get_name();
    CDate& get_date();
    virtual void set_name(std::string name);
    void set_address(std::string street, std::string number, int zip, std::string city);
    void set_date(int, int, int);

private:
    inline static unsigned int id = 0;
    unsigned int m_id;
    std::string m_name;
    CAddress m_address;
    CDate m_birth_date;
};


#endif
