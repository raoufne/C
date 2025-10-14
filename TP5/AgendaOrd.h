#ifndef AGENDAORD_H
#define AGENDAORD_H

#include "../TP4/RDV/RDV.h"
#include "NoeudRDV.h"
#include <iostream>
using namespace std;

class AgendaOrd {
private:
    NoeudRDV* premier;

public:
    AgendaOrd();
    ~AgendaOrd();

    void ajoute(const RDV& r);      
    void enleve();                   
    void enleve(const RDV& r);      
    void affiche() const;
    void vider();
};

#endif
