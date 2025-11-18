#include "Personne.h"

Personne::Personne(string nom, string prenom, string adresse, string telephone)
    : nom(nom), prenom(prenom), adresse(adresse), telephone(telephone) {}

string Personne::getNom() const { return nom; }
string Personne::getPrenom() const { return prenom; }
string Personne::getAdresse() const { return adresse; }
string Personne::getTelephone() const { return telephone; }

void Personne::setNom(string n) { nom = n; }
void Personne::setPrenom(string p) { prenom = p; }
void Personne::setAdresse(string a) { adresse = a; }
void Personne::setTelephone(string t) { telephone = t; }

void Personne::affiche() const {
    cout << "Nom : " << nom << ", Prenom : " << prenom
         << ", Adresse : " << adresse << ", Telephone : " << telephone << endl;
}
