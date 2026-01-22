#include <iostream>
#include "Vecteur.h"
#include "VecteurLimite.h"
#include"VecteurCreation.h"
using namespace std;

int main() {
    try {
        Vecteur v(5);
        v[2] = 10;
        v[11] = 3;
    }
    catch (VecteurCreation e) {
        cout << "exception creation vect nb elem = "
             << e.nb << endl;
    }
    catch (VecteurLimite e) {
        cout << "exception indice "
             << e.indice << " hors limites\n";
    }

    return 0;
}
