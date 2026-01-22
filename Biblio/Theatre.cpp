#include "Theatre.h"

Theatre::Theatre() : Livre() {
    siecle = 21; 
}

Theatre::Theatre(string code, string auteur, string titre, string editeur,
                 string isbn, Public publicCible, int siecle)
    : Livre(code, auteur, titre, editeur, isbn, publicCible) {
    
    this->siecle = siecle;
}

Theatre::~Theatre() {
}

string Theatre::siecleToString() const {
    switch(siecle) {
        case 16: return "XVIe siecle";
        case 17: return "XVIIe siecle";
        case 18: return "XVIIIe siecle";
        case 19: return "XIXe siecle";
        case 20: return "XXe siecle";
        case 21: return "XXIe siecle";
        default: return to_string(siecle) + "e siecle";
    }
}

void Theatre::afficher() const {
    cout << "======== THEATRE ========" << endl;
    cout << "Code:    " << code << endl;
    cout << "Titre:   " << titre << endl;
    cout << "Auteur:  " << auteur << endl;
    cout << "Editeur: " << editeur << endl;
    cout << "ISBN:    " << isbn << endl;
    cout << "Siecle:  " << siecleToString() << endl;  
    cout << "Public:  " << publicToString() << endl;
    cout << "Etat:    " << etatToString() << endl;
    cout << "=========================" << endl;
}

string Theatre::getType() const {
    return "Theatre";
}

int Theatre::getSiecle() const {
    return siecle;
}