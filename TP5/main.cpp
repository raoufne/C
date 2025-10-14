#include "Agenda.h"
#include "../TP4/RDV/RDV.h"
#include <iostream>
using namespace std;

int main() {
    cout<<"=== Test Agenda LIFO ==="<<endl;
    Agenda A;
    RDV r1, r2;
    r1.saisie();
    r2.saisie();
    A.ajoute(r1);
    A.ajoute(r2);
    cout<<"Affichage Agenda LIFO:"<<endl;
    A.affiche();

    cout<<"Enleve premier RDV"<<endl;
    A.enleve();
    A.affiche();

    A.vider();
    cout<<"Agenda vide:"<<endl;
    A.affiche();
    return 0;
}
