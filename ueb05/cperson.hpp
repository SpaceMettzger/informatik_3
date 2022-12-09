#ifndef CPERSON_HPP
#define CPERSON_HPP

#include "caddress.hpp"
#include "cdate.hpp"
#include <string>

class CPerson {

public:
    CPerson(const char* name, const char* street, const char* number, short zip, const char* city, short day, short month, short year);
    virtual ~CPerson();
    void print();
    CAddress& getAddress();
    std::string get_name();
    CDate& get_date();
    virtual void set_name(std::string);
    void set_address(std::string, std::string, int, std::string);
    void set_date(int, int, int);

private:
    inline static unsigned int id = 0;
    unsigned int m_id;
    const char* m_name;
    CAddress m_address;
    CDate m_birth_date;
};


#endif
