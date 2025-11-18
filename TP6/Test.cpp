#include <iostream>
#include "Personne/Personne.h"
#include "Eleve/Eleve.h"
#include "Personnel/Personnel.h"


using namespace std;

int main() {

    cout << "=== TEST PERSONNE ===" << endl;
    Personne p("Doe", "John", "Paris", "0102030405");
    p.affiche();

    cout << "\n=== TEST ELEVE ===" << endl;
    Eleve e("Smith", "Alice", "L3 Info", 3.5, "TD2");
    e.affiche();

    cout << "\n=== TEST PERSONNEL ===" << endl;
    Personnel pers("Mark", "Tom", 2500);
    pers.affiche();

    return 0;
}
