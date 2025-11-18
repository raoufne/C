#ifndef LISTEPERSONNELDYN_H
#define LISTEPERSONNELDYN_H

#include "../Personnel/Personnel.h"

class ListePersonnelDyn {
private:
    Personnel** tab;
    int nb;
    int taille;

    void doubleTableau();

public:
    ListePersonnelDyn(int tailleInit = 2);

    void ajoutPersonnel(Personnel* p);
    void afficherSalaires() const;

    ~ListePersonnelDyn();
};

#endif