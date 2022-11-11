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

class Zahl {
    private:
    int value;
    static int Anz;

    public:
    Zahl();
    Zahl(int v);
    ~Zahl();
    int get();
    int get() const;
    void print() {printf("%i", value);}
    static int getAnz() {return Anz;}
    void set(int value)
    friend int xyz(Zahl, &Z)
}

Zahl::Zahl() {
    this->value = 0;
    Anz++;
}

Zahl::Zahl(int v):
    value()
    {
    // value = v;
    Anz++;
    }

Zahl::~Zahl() {
    Anz--;
    printf("Zahl %i vernichten \n", value);

}

int Zahl::Anz = 0;

void Zahl::set(int value) {
    this->value = value;
}

int Zahl::get() {
    return value;
}

int Zahl::get() const {
    return value;
}

int xyz(Zahl, &Z) {
    Z.print();
    Z.value = 0;
}

int main {
    Zahl Z1, Z2(5);
    printf("%i\n", Z1.get());
    Z2.print();
    printf("\n");
    printf("Anz: %i\n", Z1.getAnz());
    printf("Anz: %i\n", Zahl::getAnz());
    const int a = Z1.get();
    int b = Z2.get();

    xyz(Z1);
}

class A {
    int a;
    public:
    A(int a):
        a(a) {}
    void set(int b) {a=b};
}

class B {
    A AObj;
    
    public:
    B(int x):
        AObj(x)
        {
            //AObj.set(x)
        }
}

//--------------------------------------------------------------------------------------------------------------
// 7. Datentypen in C++

//string    c-string
//string    char[]
#include <string>
#include <iostream>

using namespace std;

//string s = "Hallo";  //<- so in c
string s("Hallo");   //<- so in c++)
s += ", Welt";
s.size(); 

int main() {
    string s("Objekt");
    cout << s << endl;
    printf("%s\n" ,s.c_str());
}

#include <vector>
using namespace std;

vector<char> A;
A.size();
A.push_back('a');
A[0];
A.at(0);
A[0] = 'c';
char &r = A.at(0);
r = 'c';
A.pop_back();

//     c                        c++
// char c = (char) 3.5;     char c = char(3.5);
//                          CPerson P = CPerson("Egon");

//---------------------------------------------------------------------------------------------------------------------------
//3. Veerbung

class B {
    protected:
    int value;
    public:
    B(int v = 0): value(v) {}
    ~B() {cout << "B-Dest." << endl;}
};

//Die Klasse C erbt von der Klasse B 

class C:public B {
    bool w;
    public:
    C(bool w): w(w){}
    C(bool w, int v): B(v), w(w) {};   //<- Die Reihnefolge der Initialisierung ist wichtig. Erst vererbte Klassen, dann private Eigenschaften 
    ~C() {cout << "C-Dest." << endl;}
};

C Cobj(true);

// Die Abgeleitete Klasse ist die Klasse, die erbt.

//-----------Ableitung:
//          |   public     |  protected   |   private 
//in klasse:|----------------------------------------
// public   |   public     |  protected   |   private
// protected|  protected   |  protected   |   private
// private  | kein Zugriff | kein Zugriff | kein ZUgriff

// Vergleich Klassen - Datenstrukturen
// class c {        struct s {
//  private:         private:       // Wenn kein Zugriffsattribut mitgegeben wird, wird 
//   ...              ...           // bei Klassen private vererbt, bei structs wird public 
//  public:          public:        // vererbt
//   ...              ...
//};                }


class A {
    int value;

    public:
    A(int v): value(v) {}
    ~A() {printf("~A\n");}
    //int get() {return value;}
    virtual int get() {return value;}   // virtual int get() = 0;   -> rein virtuelle Methode. Sorgt dafür dass man kein Objekt dieser Klasse mehr erstellen kann. 
};                                      //                              Man muss die Klasse vererben damit man sie nutzen kann, und die erbenden Klassen müssen die Methode definieren.

class B: public A {

    int nr;

    public:
    B(int nr): A(0), nr(nr) {}
    ~B() {printf("~B");}
    int get() {return nr;}
};

int main() {
    A a(3);
    B b(1);
    cout << a.get();    // -> 3
    cout << b.get();    // -> 0
    // falls get() in B ebenfalls defniert ist kann man die get-Methode der Klasse A folgendermaßen aufrufen:
    cout << b.A::get();

}

// Zeiger auf Objekte:
A a (3);
A *ap = &a;

cout << ap->get();  // "->" wird nur für Zeiger verwendet. Sonst würde man den "."-operator benutzen

B b(1);
B *bp = &b;

ap = &b;        // Der Zeiger ap ist eigentlich vom Typ A, zeigt aber trotzdem auf ein Objekt der Klasse B
ap->get();      // zeigt jetzt auf Onjekt der Klasse B, ruft aber die get-Funktion der Klasse A auf, da der Zeiger als Zeiger auf ein Objekt der Klasse A definiert wurde
ap->get();      // wenn die get-Funktion der Klasse A als virtual Funktion definiert wurde, würde zur Laufzeit ausgewertet werden auf was für eine Klasse der zeiger zeigt, und die Funktion der entsprechenden Klasse ausführen

bp = &a;        // <- geht nicht, da der Zeiger der Klasse B alle eigenschaften der Klasse B erwartet. andersherum geht es, da die Klasse B alle eingenschaften der Klasse A enthält. 



// 5. (Datei-) Ein- und Ausgabe
//------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>

using namespace std;

cout << 3 << "Text" << endl;
char tmp;
tmp = cout.fill('0')    //<- wird einer variable zugeordnet, da der Rückgabewert der rsprüngliche Wert von .fill ist. Damit kann man den Wert später wieder zurücksetzen.
cout.width(5);
cout << 3 << endl;  //-> 00003
cout.fill(tmp);         // Dadurch wird der .fill-Wert wieder auf den Ursprungswert zurückgesetzt. 

cout.flags();           // Gibt an welche Flags gesetzt sind 
cout.flags(ios::hex);   // Setzt Flag für Hexadezimalzahlen. Wird dauerhaft gesetzt. 
cout.flags(ios::dec);   // Setzt Flag für Dezimalzahlen. 
                        // Beides ungünstig, da dadurch die Bits für andere Flags überschrieben werden.
long f = count.flags();

cout.setf(ios::dec);
cout.setf(ios::basefield, ios::dec);

#include <iomanip>

cout << setfill('0') << setw(5) << hex << 65 << endl;       // -> gibt die Zahl 65 in hexadezimal aus mit führenden Nullen mit einer Breite von 5 


// Nutzereingabe

int i; char T[21];

cin >> i;
cin.ignore(100, '\n');
char c = cin.peek();
char d = cin.get();
cin.putback(d);
cin.getline(T, 20, '\n');

#include <fstream>

using namespace std;

ifstream input;
ofstream output;
fstream inoutput;

input.open("text.txt", ios::in | ios::binary);
if (input) {
    input.close();
}


// 8. Dynamische Speicherverwaltung
// --------------------------------------------------------------------------------------------------------------------------------------------------

// new 
int* Zahlen = new int[10];
if (Zahlen) {
    *Zahlen = 0;
    Zahlen[0] = 0;
    delete [] Zahlen;
}

class CRoom {

};

cRoom *Neu = new cRoom("D113", 28);
if (Neu) {
    Neu.load(Datenstrom);
}

// 6. Namensräume
//------------------------------------------------------------------------------------------------------------------------------------------------------

using namespace std;    //using-Direktive

std::cout << //...      //qualifizierter Namensraum-Name

using std::cout;        // using-Deklaration
using std::cin; 

using namespace MyNS;
using MyNS::a;
MyNS::a = 0;
a = 0;
::a = 1;
using ::a;

namespace A{
    int i;
    namespace B {
        int i;
    }
}

int main() {
    int i;
    i = 0;
    A::i = 0;
    A::B::i = 0;
}

namespace {         // Namensloser Namensraum (macht keinen Sinn)
    int i;
    namespace A {
        int i;
    }
}

int main() {
    i = 0;      // bereits im namenslosen Namensraum deklariert
    using namespace A;
    ::i = 0;
}