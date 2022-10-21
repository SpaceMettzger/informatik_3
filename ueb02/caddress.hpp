#ifndef CAddress_HPP
#define CAddress_HPP

class CAddress {

public:
    CAddress(const char*, const char*, int, const char*);
    void print();

private:
    const char* m_street;
    const char* m_number;
    int m_zip;
    const char* m_city;

};

#endif
