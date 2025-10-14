#include <iostream>
#include "RDV/RDV.h"
using namespace std;

int main() {
    RDV r1;
    cout << "=== Saisie du RDV 1 ===" << endl;
    r1.saisie();

    cout << "\n=== Affichage du RDV 1 ===" << endl;
    r1.affiche();

    RDV r2;
    cout << "\n=== Saisie du RDV 2 ===" << endl;
    r2.saisie();

    if (r1.estCompatibleAvec(r2))
        cout << "Les rendez-vous sont compatibles." << endl;
    else
        cout << "Conflit ! Rendez-vous en meme temps." << endl;

    return 0;
}
