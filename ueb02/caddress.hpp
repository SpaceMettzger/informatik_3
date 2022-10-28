#ifndef CAddress_HPP
#define CAddress_HPP

class CAddress {

public:
    CAddress(const char*, const char*, unsigned int, const char*);
    void print();

private:
    const char* m_street;
    const char* m_number;
    unsigned int m_zip;
    const char* m_city;

};

#endif
