#include "Vector.h"

int main() {
    cout << "Compteur initial = " << Vector::getCompteur() << endl;

    double vals1[] = {1, 2, 3};
    double vals2[] = {4, 5, 6};

    Vector v1(3, vals1);
    Vector v2(3, vals2);

    cout << "v1 = "; v1.afficher(); cout << endl;
    cout << "v2 = "; v2.afficher(); cout << endl;

    cout << "Norme de v1 = " << v1.norme() << endl;
    cout << "Produit scalaire v1.v2 = " << v1.produitScalaire(v2) << endl;

    Vector v3 = v1 + v2;
    cout << "v1 + v2 = "; v3.afficher(); cout << endl;

    Vector v4 = v1 * 2;
    cout << "v1 * 2 = "; v4.afficher(); cout << endl;

    cout << "v1 == v2 ? " << (v1.egal(v2) ? "Oui" : "Non") << endl;

    Vector v5(3, vals1);
    cout << "v1 == v4 ? " << (v1.egal(v5) ? "Oui" : "Non") << endl;

    cout << "Compteur actuel = " << Vector::getCompteur() << endl;

    delete &v2;
    cout << "Compteur actuel = " << Vector::getCompteur() << endl;
        

    return 0;
}
