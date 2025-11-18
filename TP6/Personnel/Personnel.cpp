#include "Personnel.h"

Personnel::Personnel(string nom, string prenom, float salaire)
    : Personne(nom, prenom), salaire(salaire) {}

void Personnel::setSalaire(float s) { salaire = s; }
float Personnel::getSalaire() const { return salaire; }

float Personnel::calculSalaire() const {
    return salaire;
}

void Personnel::affiche() const {
    Personne::affiche();
    cout << "Salaire : " << salaire << endl;
}
