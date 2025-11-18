//meme que dans le TP6/ListePersonnel/ListePersonnel.h
#ifndef LISTEPERSONNELAP_H
#define LISTEPERSONNELAP_H

#include "../Personnel/Personnel.h"

class ListePersonnelAP {
private:
    Personnel* tab[100];
    int nb;

public:
    ListePersonnelAP();

    void ajoutPersonnel(Personnel* p);
    void afficherSalaires() const;
};

#endif