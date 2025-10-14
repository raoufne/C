#include "Date.h"

int main() {
    cout << "Nombre d'instances au depart: " << Date::getCompteur() << endl;

    Date d1;
    cout << "Saisir les coordonnees du Date d1: " << endl;
    d1.saisir();

    Date d2(29, 2, 2020); 
    Date d3 = d2;  

    cout << "\nAffichage des Dates :" << endl;
    cout << "p1 = "; d1.affiche(); cout << endl;
    cout << "p2 = "; d2.affiche(); cout << endl;
    cout << "p3 (copie de p2) = "; d3.affiche(); cout << endl;


    cout << "\nCompteur d'instances: " << Date::getCompteur() << endl; 
    
    delete &d2;
    cout << "\nCompteur d'instances: " << Date::getCompteur() << endl; 

    return 0;
}