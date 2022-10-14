// Objektorientierte Programmierung

// Unterschiede C/C++
//----------------------------------------------------------------------------------------------------------------------------------------------------
//In-Line Kommentare
// Bisher: // zum erstellen eines in-line Kommentars. Jetzt: 
/*Beispieltext*/

// Variablendeklaration
// Variablen werden in C++ in der Regel am Anfang des Programmes angelegt, nicht mittem im Programm

// Arrays aus Variablen
// Variablen (int) können bei der Deklaration von Arrays zur Bestimmung der Größe des Arrays genutzt werden
// in C war das nicht möglich
// int a = 5;
// int Werte[a];

// Structs
// Nach dem Erstellen von Datenstrukturen muss man in C++ neue instanzen der Datenstruktur nicht mit dem Schlüsselwort struct deklarieren
// struct s {
//
// };
// struct s E;  <- So war es bisher
// s E;         <- So geht es jetzt

// Referenzen
// int i = 1;
// int &refi = i;
// Eine Referenz ist ein Alias für die referenzierte Variable. Sie belegt keinen Arbeitsspeicher.
// Eine Referenz muss immer initialisiert werden.

// Default-Werte
// In C++ können für Funktionen definiert werden
// void f (int a, int b = 0) {
// ...   
// }
// f(5);
// f(5, 7);

// Doppelte Funktionsnamen
// In C++ ist es möglich, eine Funktion mit unterschiedlichen Parametern aber dem gleichen Funktionsnamen zu definieren (Überbelegung)
// int f (int a) {return a;}        -> intern als fii gespeichert (i = int parameter, i = int return value)
// int f (double a) {return a;}     -> intern als fdd gespeichert (d = double parameter, d = double return value)

// Inline Funktionen
// inline int quad(int x) {return x*x;}
// int a = 3, b;
// b = quad(a);     -> So, als wäre der Funktionskörper direkt in die Zeile geschrieben. Ohne inline würde ein Funktionsaufruf durchgeführt werden.

// extern C
// Nachlesen


//----------------------------------------------------------------------------------------------------------------------------------------------------
// Objekte und Klassen

// Klassen entsprechen gedanklich Datentypen
// Objekte entsprechen gedanklich Variablen

int i;
ifstream Datei;

class K {                       // struct S {
    private:                    //      int Wert;
        int Wert;               //      ...
    public:                     //      ...
         void setWert(int W) {  //      ...
            Wert = W;           // };
         }                      //
};                              

K KObj;                         // S SObj;
KObj.Wert = 0;                  // SObj.Wert = 0;
 //-> geht nicht für Klassen, weil Wert private ist 

# include <stdio.h>

class CAmpel {
    int rot, gelb, gruen;
    
    public:
        void setRot();
        CAmpel();
        CAmpel(int, int);
        CAmpel(int, int, int = 0);
        ~CAmpel();
};

// Methoden von Klassen werden außerhalb von Klassen definiert.

void CAmpel::setRot() {
    gelb = gruen = 0;
    rot = 1;
}

// Klassen müssen inititalisiert werden. Das geschieht über einen Konstruktor:
CAmpel::CAmpel() {
    rot = 1;
    gelb = gruen = 0;
}

// Es können mehrere Konstruktoren für eine Klasse erstellt werden. Das macht Sinn, wenn man den Aufruf mit unterschiedlich vielen Variablen
// oder unterschiedlichen Variablentypen ermöglichen will.
CAmpel::CAmpel(int r, int ge, int gr) {
    rot = r;
    gelb = ge;
    gruen = gr;
}

// Durch das hinzufügen einer Initialisierungsliste werden die Werte der Klasse sofort initialisiert. Dadurch müssen die Variablen nicht erst wieder 
// aus dem Speicher geholt werden. Dadurch wird die Erstellung der Klasse beschleunigt. 
CAmpel::CAmpel(int r, int ge) 
    : rot(r), gelb(ge) {
}

// Ein Destruktor kann nur einmal pro Klasse erstellt werden. Er wird zu Ende der Laufzeit aufgerufen. Das kann Sinn machen, wenn man zum Ende 
// reservierten Speicher wieder freigeben möchte oder etwas aus der Klasse in eine Textdatei schreiben möchte. 
CAmpel::~CAmpel() {
    rot = 1;
    gelb = gruen = 0;
}

int main() {
    CAmpel A1, A2;
    CAmpel A3(1, 0), A4(0, 0, 1);
    A1.setRot();

    return 0;
}
