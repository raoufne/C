#ifndef LISTEPERSONNEL_H
#define LISTEPERSONNEL_H

#include "../Personnel/Personnel.h"

class ListePersonnel {
private:
    Personnel* tab[100];
    int nb;

public:
    ListePersonnel();

    void ajoutPersonnel(Personnel* ptPersonnel);
    void afficherSalaires() const;
};

#endif