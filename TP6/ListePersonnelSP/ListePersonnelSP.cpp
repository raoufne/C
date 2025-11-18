#include "ListePersonnelSP.h"
#include <iostream>
using namespace std;

ListePersonnelSP::ListePersonnelSP() : nb(0) {}

void ListePersonnelSP::ajoutPersonnel(const Personnel& p) {
    if(nb < 100) {
        tab[nb++] = p;
    } else {
        cout << "Tableau plein !" << endl;
    }
}

void ListePersonnelSP::afficherSalaires() const {
    cout << "=== SALAIRES (objets) ===" << endl;

    for(int i = 0; i < nb; i++) {
        cout << tab[i].getNom() << " "
             << tab[i].getPrenom()
             << " : " << tab[i].calculSalaire()
             << endl;
    }
}
