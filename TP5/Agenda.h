#ifndef AGENDA_H
#define AGENDA_H

#include "../TP4/RDV/RDV.h"
#include "NoeudRDV.h"
#include <iostream>
using namespace std;

class Agenda {
private:
    NoeudRDV* premier;

public:
    Agenda();
    Agenda(const Agenda& other);
    ~Agenda();

    void ajoute(const RDV& r);       
    void enleve();                    
    void enleve(const RDV& r);       
    void affiche() const;
    void vider();                    
};

#endif
