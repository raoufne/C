#ifndef NOEUDRDV_H
#define NOEUDRDV_H

#include "../TP4/RDV/RDV.h"

class NoeudRDV {
private:
    RDV rdv;
    NoeudRDV* suivant;

public:
    NoeudRDV(const RDV& r);
    NoeudRDV(const RDV& r, NoeudRDV* s);

    RDV& getRDV();
    NoeudRDV* getSuivant() const;
    void setSuivant(NoeudRDV* s);
};

#endif
