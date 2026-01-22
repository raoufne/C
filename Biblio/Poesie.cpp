#include "Poesie.h"

Poesie::Poesie() : Livre() {
    typePoesie = VERS;
}

Poesie::Poesie(string code, string auteur, string titre, string editeur,
               string isbn, Public publicCible, TypePoesie typePoesie)
    : Livre(code, auteur, titre, editeur, isbn, publicCible) {
    
    this->typePoesie = typePoesie;
}

Poesie::~Poesie() {
}

string Poesie::typePoesieToString() const {
    switch(typePoesie) {
        case VERS:          return "Vers";
        case PROSE:         return "Prose";
        case VERS_ET_PROSE: return "Vers et Prose";
        default:            return "Inconnu";
    }
}

void Poesie::afficher() const {
    cout << "======== POESIE ========" << endl;
    cout << "Code:    " << code << endl;
    cout << "Titre:   " << titre << endl;
    cout << "Auteur:  " << auteur << endl;
    cout << "Editeur: " << editeur << endl;
    cout << "ISBN:    " << isbn << endl;
    cout << "Type:    " << typePoesieToString() << endl;  
    cout << "Public:  " << publicToString() << endl;
    cout << "Etat:    " << etatToString() << endl;
    cout << "========================" << endl;
}

string Poesie::getType() const {
    return "Poesie";
}

TypePoesie Poesie::getTypePoesie() const {
    return typePoesie;
}