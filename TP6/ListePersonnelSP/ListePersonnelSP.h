#ifndef LISTEPERSONNELSP_H
#define LISTEPERSONNELSP_H

#include "../Personnel/Personnel.h"

class ListePersonnelSP {
private:
    Personnel tab[100];
    int nb;

public:
    ListePersonnelSP();

    void ajoutPersonnel(const Personnel& p);
    void afficherSalaires() const;
};

#endif