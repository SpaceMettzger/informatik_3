#include <iostream>

using namespace std;

#include "cbookings.hpp"

int main()
{
   CBookings Belegungen("belegungen.xml");

   Belegungen(ofPersons);
   Belegungen(ofStudents);
   Belegungen(ofTeachers);
   Belegungen(ofBookings);
   // freiwillig:
//   Belegungen(ofScheduleOfStudents);
//   Belegungen(ofScheduleOfStudies);

   return 0;
}
