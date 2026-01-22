#include "Livre.h"

int Livre::nombreTotalLivres = 0;

Livre::Livre() {
    code = "";
    auteur = "";
    titre = "";
    editeur = "";
    isbn = "";
    publicCible = TOUT_PUBLIC;
    etat = LIBRE;

    nombreTotalLivres++;
}

Livre::Livre(string code, string auteur, string titre, 
             string editeur, string isbn, Public publicCible) {
    
    this->code = code;
    this->auteur = auteur;
    this->titre = titre;
    this->editeur = editeur;
    this->isbn = isbn;
    this->publicCible = publicCible;
    this->etat = LIBRE;  

    nombreTotalLivres++;
}

Livre::~Livre() {
    nombreTotalLivres--;
}

string Livre::getType() const {
    return "Livre";
}

string Livre::getCode() const {
    return code;
}

string Livre::getAuteur() const {
    return auteur;
}

string Livre::getTitre() const {
    return titre;
}

string Livre::getEditeur() const {
    return editeur;
}

string Livre::getIsbn() const {
    return isbn;
}

Public Livre::getPublicCible() const {
    return publicCible;
}

Etat Livre::getEtat() const {
    return etat;
}

void Livre::setEtat(Etat nouvelEtat) {
    etat = nouvelEtat;
}

int Livre::getNombreTotalLivres() {
    return nombreTotalLivres;
}

string Livre::etatToString() const {
    switch(etat) {
        case LIBRE:     return "Libre";
        case EMPRUNTE:  return "Emprunte";
        case PRETE:     return "Prete";
        default:        return "Inconnu";
    }
}

string Livre::publicToString() const {
    switch(publicCible) {
        case ADULTE:      return "Adulte";
        case ADOS:        return "Adolescents";
        case JEUNESSE:    return "Jeunesse";
        case TOUT_PUBLIC: return "Tout public";
        default:          return "Inconnu";
    }
}

bool Livre::estDisponible() const {
    return (etat == LIBRE);
}

bool Livre::operator==(const Livre& autre) const {
    return (this->code == autre.code);
}

ostream& operator<<(ostream& os, const Livre& livre) {
    os << "Code: " << livre.code << " | ";
    os << "Titre: " << livre.titre << " | ";
    os << "Auteur: " << livre.auteur << " | ";
    os << "Etat: " << livre.etatToString();
    return os;
}