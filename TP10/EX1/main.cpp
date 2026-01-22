#include <iostream>
#include "B.h"
#include "Erreur.h"
#include "Erreur2.h"

using namespace std;

int main() {

    try {
        B a(1);
        cout << "apres creation a(1)\n";
    }
    catch (Erreur er) {
        cout << "exception erreur: " << er.num << "\n";
    }
    catch (Erreur2 er2) {
        cout << "exception Erreur2: "
             << er2.num << " " << er2.code << "\n";
    }

    cout << "suite\n";

    try {
        B b(1);
        cout << "apres creation b(1)\n";
    }
    catch (Erreur2 er2) {
        cout << "exception Erreur2: "
             << er2.num << " " << er2.code << "\n";
    }
    catch (Erreur er) {
        cout << "exception erreur: " << er.num << "\n";
    }

    return 0;
}
