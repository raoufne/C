#include "Album.h"

Album::Album() : Livre() {
    typeIllustration = DESSINS;
}

Album::Album(string code, string auteur, string titre, string editeur,
             string isbn, Public publicCible, TypeIllustration typeIllustration)
    : Livre(code, auteur, titre, editeur, isbn, publicCible) {
    
    this->typeIllustration = typeIllustration;
}

Album::~Album() {
}

string Album::typeIllustrationToString() const {
    switch(typeIllustration) {
        case PHOTOS:            return "Photos";
        case DESSINS:           return "Dessins";
        case PHOTOS_ET_DESSINS: return "Photos et Dessins";
        default:                return "Inconnu";
    }
}

void Album::afficher() const {
    cout << "======== ALBUM ========" << endl;
    cout << "Code:         " << code << endl;
    cout << "Titre:        " << titre << endl;
    cout << "Auteur:       " << auteur << endl;
    cout << "Editeur:      " << editeur << endl;
    cout << "ISBN:         " << isbn << endl;
    cout << "Illustrations:" << typeIllustrationToString() << endl;  // Spécifique
    cout << "Public:       " << publicToString() << endl;
    cout << "Etat:         " << etatToString() << endl;
    cout << "=======================" << endl;
}

string Album::getType() const {
    return "Album";
}

TypeIllustration Album::getTypeIllustration() const {
    return typeIllustration;
}