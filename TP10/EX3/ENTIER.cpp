#include "ENTIER.h"

int ENTIER::valeurMini = -100;
int ENTIER::valeurMaxi = 100;

void ENTIER::verifier(int v) {
    if (v < valeurMini)
        throw HorsLimite("debordement par le bas");
    if (v > valeurMaxi)
        throw HorsLimite("debordement par le haut");
}

ENTIER::ENTIER(int v) {
    verifier(v);
    valeur = v;
}

ENTIER ENTIER::operator+(const ENTIER& e) {
    return ENTIER(valeur + e.valeur);
}

ENTIER ENTIER::operator-(const ENTIER& e) {
    return ENTIER(valeur - e.valeur);
}

ENTIER ENTIER::operator*(const ENTIER& e) {
    return ENTIER(valeur * e.valeur);
}

ENTIER ENTIER::operator/(const ENTIER& e) {
    return ENTIER(valeur / e.valeur);
}
