#include "B.h"
#include "Erreur2.h"

B::B(int n) {
    if (n == 1) {
        Erreur2 er2;
        er2.num = 999;
        er2.code = 12;
        throw er2;
    }
}
