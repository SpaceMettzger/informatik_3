#include <iostream>

using namespace std;

#include "cbookings.hpp"

int main()
{
   CBookings Belegungen("belegungen.xml");

   Belegungen.print();

   return 0;
}
