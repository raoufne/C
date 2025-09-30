#include "Point.h"

int main() {
    cout << "Nombre d'instances au depart: " << Point::getCompteur() << endl;

    Point p1;
    cout << "Saisir les coordonnees du point p1: " << endl;
    p1.saisir();

    Point p2(3.0, 4.0, 5.0); 
    Point p3 = p2;  

    cout << "\nAffichage des points :" << endl;
    cout << "p1 = "; p1.afficher(); cout << endl;
    cout << "p2 = "; p2.afficher(); cout << endl;
    cout << "p3 (copie de p2) = "; p3.afficher(); cout << endl;

    cout << "\nTranslation de p1 de (1,2,3)" << endl;
    p1.translater(1, 2, 3);
    cout << "p1 apres translation = "; p1.afficher(); cout << endl;

    cout << "\nDistance entre p1 et p2 = " << p1.distance(p2) << endl;

    cout << "\nCompteur d'instances: " << Point::getCompteur() << endl; 
    
    delete &p2;
    cout << "\nCompteur d'instances: " << Point::getCompteur() << endl; 

    return 0;
}