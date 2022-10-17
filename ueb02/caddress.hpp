#ifndef CAddress_HPP
#define CAddress_HPP

class CAddress {

public:
    CAddress(char, char, int, char);
    void print();

private:
    char m_street;
    char m_number;
    int m_zip;
    char m_city;
    
};

#endif