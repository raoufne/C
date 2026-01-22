#include <iostream>
#include "ENTIER.h"

using namespace std;

int main() {
    try {
        ENTIER a(90);
        ENTIER b(20);
        ENTIER c = a + b;
    }
    catch (HorsLimite& e) {
        cout << e.what() << endl;
    }

    return 0;
}
