#ifndef LISTEPERSONNELSP_H
#define LISTEPERSONNELSP_H

#include "../Personnel/Personnel.h"

// changer la classe personnel en non statique -- ( remove = 0 dans Personnel.h ) pour que ça marche
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