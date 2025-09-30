#include "ArrayOfInteger.h"

int main() {
    cout << "Compteur initial = " << ArrayOfInteger::getCompteur() << endl;

    ArrayOfInteger arr1;
    arr1.ajouter(5);
    arr1.ajouter(10);
    arr1.ajouter(5); // doublon ignoré
    cout << "arr1 = "; arr1.afficher();

    int vals[] = {1, 2, 3, 4, 5};
    ArrayOfInteger arr2(5, vals);
    cout << "arr2 = "; arr2.afficher();

    cout << "arr1 contient 10 ? " << (arr1.contains(10) ? "Oui" : "Non") << endl;
    cout << "arr2 contient 8 ? " << (arr2.contains(8) ? "Oui" : "Non") << endl;

    arr2.retirer(3);
    cout << "arr2 après suppression de 3 = "; arr2.afficher();

    cout << "arr1 == arr2 ? " << (arr1.egal(arr2) ? "Oui" : "Non") << endl;

    cout << "Compteur final = " << ArrayOfInteger::getCompteur() << endl;

    return 0;
}
