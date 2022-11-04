#include <iostream>

using namespace std;

#include "ctime.hpp"
#include "cblock.hpp"
#include "croom.hpp"
#include "cperson.hpp"
#include "cevent.hpp"
#include "cevents.hpp"

int main()
{
   // Uhrzeiten
   CTime Zeit0800( 8,  0);
   CTime Zeit1000(10,  0);
   CTime Zeit1215(12, 15);
   CTime Zeit1415(14, 15);
   CTime Zeit1600(16,  0);
   CTime Zeit1745(17, 45);
   CTime Zeit1930(19, 30);

   // Bloecke
   CBlock Block1( 1, Zeit0800);
   CBlock Block2( 2, Zeit1000);
   CBlock Block3( 3, Zeit1215);
   CBlock Block4( 4, Zeit1415);
   CBlock Block5( 5, Zeit1600);
   CBlock Block6( 6, Zeit1745);
   CBlock Block7( 7, Zeit1930);

   // Raeume
   CRoom D113("D 113", "Haus Bauswesen",  24);
   CRoom D114("D 114", "Haus Bauswesen",  28);
   CRoom D117("H3   ", "Haus Bauwesen ", 104);
   CRoom D136("H5   ", "Haus Bauwesen ", 104);
   CRoom D209("D 209", "Haus Bauwesen ",  35);
   CRoom D419("D 419", "Haus Bauswesen",  40);
   CRoom B301("B 301", "Haus Gauss    ", 100);

   // Personen
   CPerson Dozent1( "Kevin Kaufmann", "Kaiserstr.",    "38",  12075, "Berlin",       15,  6, 1959);
   CPerson Dozent2( "Nathan Neuling", "Neue Str.",     "7",   10777, "Berlin",        9,  9, 1969);
   CPerson Dozent3( "Sabine Sauber ", "Saubere Gasse", "1",   17001, "Auf dem Land",  3,  1, 1962);
   CPerson Dozent4( "Willi Witzig  ", "Wunderweg",     "99",  15911, "Nauen",         9, 11, 1976);

   // Veranstaltungen
   CEvent Event1("SU OOP                  ", &Dozent1, &D136, &Block4, Fr, 1);
   CEvent Event2("Ueb OOP                 ", &Dozent1, &D113, &Block5, Fr, 2);
   CEvent Event3("Ueb OOP                 ", &Dozent1, &D113, &Block6, Fr, 2);
   CEvent Event4("SU Mathe III            ", &Dozent2, &B301, &Block2, Do, 1);
   CEvent Event5("SU Mathe III            ", &Dozent2, &B301, &Block3, Do, 1);
   CEvent Event6("Ueb Mathe III           ", &Dozent2, &D209, &Block1, Do, 1);
   CEvent Event7("Englisch                ", &Dozent3, &D419, &Block5, Mi, 1);
   CEvent Event8("SU Systemprogrammierung ", &Dozent4, &D117, &Block3, Di, 1);
   CEvent Event9("Ueb Systemprogrammierung", &Dozent4, &D114, &Block4, Di, 1);
    /*
   CEvents Veranstaltungen;

   Veranstaltungen.addEvent(&Event1);
   Veranstaltungen.addEvent(&Event2);
   Veranstaltungen.addEvent(&Event3);
   Veranstaltungen.addEvent(&Event4);
   Veranstaltungen.addEvent(&Event5);
   Veranstaltungen.addEvent(&Event6);
   Veranstaltungen.addEvent(&Event7);
   Veranstaltungen.addEvent(&Event8);
   Veranstaltungen.addEvent(&Event9);
    */
   //Veranstaltungen.print();
   cout << endl;

   return 0;
}
