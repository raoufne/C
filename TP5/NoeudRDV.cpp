#include "NoeudRDV.h"

NoeudRDV::NoeudRDV(const RDV& r) : rdv(r), suivant(nullptr) {}

NoeudRDV::NoeudRDV(const RDV& r, NoeudRDV* s) : rdv(r), suivant(s) {}

RDV& NoeudRDV::getRDV() { return rdv; }
NoeudRDV* NoeudRDV::getSuivant() const { return suivant; }
void NoeudRDV::setSuivant(NoeudRDV* s) { suivant = s; }


