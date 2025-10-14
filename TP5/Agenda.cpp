#include "Agenda.h"

Agenda::Agenda() : premier(nullptr) {}

Agenda::Agenda(const Agenda& other) : premier(nullptr) {
    NoeudRDV* courant = other.premier;
    while(courant) {
        ajoute(courant->getRDV());
        courant = courant->getSuivant();
    }
}

Agenda::~Agenda() { vider(); }

void Agenda::ajoute(const RDV& r) {
    NoeudRDV* n = new NoeudRDV(r, premier);
    premier = n;
}

void Agenda::enleve() {
    if(!premier) return;
    NoeudRDV* temp = premier;
    premier = premier->getSuivant();
    delete temp;
}

void Agenda::enleve(const RDV& r) {
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

void Agenda::affiche() const {
    NoeudRDV* courant = premier;
    while(courant){
        courant->getRDV().affiche();
        courant = courant->getSuivant();
    }
}

void Agenda::vider() {
    while(premier) enleve();
}
