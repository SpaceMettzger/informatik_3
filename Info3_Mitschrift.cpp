// Objektorientierte Programmierung

// Unterschiede C/C++
//----------------------------------------------------------
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
// In C++ ist es möglich, eine Funktion mit unterschiedlichen Parametern aber dem gleichen Funktionsnamen zu definieren
// int f (int a) {return a;}        -> intern als fii gespeichert (i = int parameter, i = int return value)
// int f (double a) {return a;}     -> intern als fdd gespeichert (d = double parameter, d = double return value)

// Inline Funktionen
// inline int quad(int x) {return x*x;}
// int a = 3, b;
// b = quad(a);     -> So, als wäre der Funktionskörper direkt in die Zeile geschrieben. Ohne inline würde ein Funktionsaufruf durchgeführt werden.

// extern C
// Nachlesen