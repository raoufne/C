#ifndef ENTIER_H
#define ENTIER_H

#include "HorsLimite.h"

class ENTIER {
    int valeur;
    static int valeurMini;
    static int valeurMaxi;

    void verifier(int v);

public:
    ENTIER(int v);

    ENTIER operator+(const ENTIER& e);
    ENTIER operator-(const ENTIER& e);
    ENTIER operator*(const ENTIER& e);
    ENTIER operator/(const ENTIER& e);
};

#endif
