#include "AgendaOrd.h"

AgendaOrd::AgendaOrd() : premier(nullptr) {}
AgendaOrd::~AgendaOrd() { vider(); }

void AgendaOrd::ajoute(const RDV& r) {
    NoeudRDV* n = new NoeudRDV(r);
    if(!premier || r.estSuperieur(premier->getRDV())==false){
        n->setSuivant(premier);
        premier = n;
        return;
    }
    NoeudRDV* courant = premier;
    while(courant->getSuivant() && r.estSuperieur(courant->getSuivant()->getRDV()))
        courant = courant->getSuivant();
    n->setSuivant(courant->getSuivant());
    courant->setSuivant(n);
}

void AgendaOrd::enleve() {
    if(!premier) return;
    NoeudRDV* temp = premier;
    premier = premier->getSuivant();
    delete temp;
}

void AgendaOrd::enleve(const RDV& r) {
    if(!premier) return;
    if(premier->getRDV().estEgal(r)){
        enleve();
        return;
    }
    NoeudRDV* courant = premier;
    while(courant->getSuivant()){
        if(courant->getSuivant()->getRDV().estEgal(r)){
            NoeudRDV* temp = courant->getSuivant();
            courant->setSuivant(temp->getSuivant());
            delete temp;
            return;
        }
        courant = courant->getSuivant();
    }
}

void AgendaOrd::affiche() const {
    NoeudRDV* courant = premier;
    while(courant){
        courant->getRDV().affiche();
        courant = courant->getSuivant();
    }
}

void AgendaOrd::vider() {
    while(premier) enleve();
}
