#include <iostream>

using namespace std;

#include "cbookings.h"

int main()
{
   CBookings Belegungen("belegungen.xml");

   Belegungen.print();

   return 0;
}
