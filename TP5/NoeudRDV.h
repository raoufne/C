#ifndef NOEUDRDV_H
#define NOEUDRDV_H

#include "../TP4/RDV/RDV.h"

class NoeudRDV {
private:
    RDV rdv;
    NoeudRDV* suivant;

public:
    NoeudRDV(const RDV& r) : rdv(r), suivant(nullptr) {}
    NoeudRDV(const RDV& r, NoeudRDV* s) : rdv(r), suivant(s) {}

    RDV& getRDV() { return rdv; }
    NoeudRDV* getSuivant() const { return suivant; }
    void setSuivant(NoeudRDV* s) { suivant = s; }
};

#endif
