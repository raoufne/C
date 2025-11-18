#include "ListePersonnelAP.h"
#include <iostream>
using namespace std;

ListePersonnelAP::ListePersonnelAP() : nb(0) {}

void ListePersonnelAP::ajoutPersonnel(Personnel* p) {
    if(nb < 100) {
        tab[nb++] = p;
    } else {
        cout << "Tableau plein !" << endl;
    }
}

void ListePersonnelAP::afficherSalaires() const {
    cout << "=== SALAIRES (pointeurs) ===" << endl;

    for(int i = 0; i < nb; i++) {
        cout << tab[i]->getNom() << " "
             << tab[i]->getPrenom()
             << " : " << tab[i]->calculSalaire()
             << endl;
    }
}
