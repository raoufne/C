#include "ListePersonnel.h"
#include <iostream>
using namespace std;

ListePersonnel::ListePersonnel() : nb(0) {}

void ListePersonnel::ajoutPersonnel(Personnel* ptPersonnel) {
    if(nb < 100) {
        tab[nb++] = ptPersonnel;
    } else {
        cout << "Tableau plein !" << endl;
    }
}

void ListePersonnel::afficherSalaires() const {
    cout << "=== Salaires du personnel ===" << endl;
    for(int i = 0; i < nb; i++) {
        cout << tab[i]->getNom() << " " << tab[i]->getPrenom()
             << " : " << tab[i]->calculSalaire() << endl;
    }
}
