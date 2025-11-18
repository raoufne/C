#include "ListePersonnelDyn.h"
#include <iostream>
using namespace std;

ListePersonnelDyn::ListePersonnelDyn(int tailleInit)
    : nb(0), taille(tailleInit)
{
    tab = new Personnel*[taille];
}

void ListePersonnelDyn::doubleTableau() {
    taille *= 2;
    Personnel** nouveau = new Personnel*[taille];
    for(int i = 0; i < nb; i++)
        nouveau[i] = tab[i];

    delete[] tab;
    tab = nouveau;

    cout << "[INFO] Tableau doublé : nouvelle taille = " << taille << endl;
}

void ListePersonnelDyn::ajoutPersonnel(Personnel* p) {
    if(nb >= taille)
        doubleTableau();

    tab[nb++] = p;
}

void ListePersonnelDyn::afficherSalaires() const {
    cout << "=== Salaires (tableau dynamique) ===" << endl;
    for(int i = 0; i < nb; i++) {
        cout << tab[i]->getNom() << " " << tab[i]->getPrenom()
             << " : " << tab[i]->calculSalaire() << endl;
    }
}

ListePersonnelDyn::~ListePersonnelDyn() {
    delete[] tab;
}