#include <iostream>
#include "Personne/Personne.h"

using namespace std;

int main() {

    cout << "=== TEST PERSONNE ===" << endl;
    Personne p("Doe", "John", "Paris", "0102030405");
    p.affiche();

    return 0;
}
