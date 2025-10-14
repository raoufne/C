#include "Agenda.h"
#include "AgendaOrd.h"
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

    cout<<"\n=== Test Agenda Ordonné ==="<<endl;
    AgendaOrd B;
    RDV r3, r4, r5;
    r3.saisie();
    r4.saisie();
    r5.saisie();
    B.ajoute(r3);
    B.ajoute(r4);
    B.ajoute(r5);

    cout<<"Affichage Agenda Ordonné:"<<endl;
    B.affiche();

    cout<<"Enleve RDV spécifique (r4)"<<endl;
    B.enleve(r4);
    B.affiche();

    B.vider();
    cout<<"Agenda Ordonné vide:"<<endl;
    B.affiche();



    return 0;
}
