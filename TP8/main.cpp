#include "Vector.h"
#include <iostream>
using namespace std;

int main() {

    Vector v1(1,2,3);
    Vector v2(4,5,6);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    Vector v3 = v1 + v2;
    cout << "v1 + v2 = " << v3 << endl;

    cout << "Produit scalaire = " << (v1 * v2) << endl;

    cout << "3 * v1 = " << (3 * v1) << endl;

    v1 += v2;
    cout << "v1 += v2 => " << v1 << endl;

    cout << "v1 == v2 ? " << (v1 == v2) << endl;

    cout << "Nombre d'instances de Vector : " << Vector::getCompteur() << endl;    

    return 0;
}
