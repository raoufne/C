#include "BandeDessinee.h"

BandeDessinee::BandeDessinee() : Livre() {
    dessinateur = "Inconnu";
}

BandeDessinee::BandeDessinee(string code, string auteur, string titre, 
                             string editeur, string isbn, Public publicCible, 
                             string dessinateur)
    : Livre(code, auteur, titre, editeur, isbn, publicCible) {
    
    this->dessinateur = dessinateur;
}

BandeDessinee::~BandeDessinee() {
}

void BandeDessinee::afficher() const {
    cout << "===== BANDE DESSINEE =====" << endl;
    cout << "Code:       " << code << endl;
    cout << "Titre:      " << titre << endl;
    cout << "Scenariste: " << auteur << endl;      
    cout << "Dessinateur:" << dessinateur << endl; 
    cout << "Editeur:    " << editeur << endl;
    cout << "ISBN:       " << isbn << endl;
    cout << "Public:     " << publicToString() << endl;
    cout << "Etat:       " << etatToString() << endl;
    cout << "==========================" << endl;
}

string BandeDessinee::getType() const {
    return "BandeDessinee";
}

string BandeDessinee::getDessinateur() const {
    return dessinateur;
}