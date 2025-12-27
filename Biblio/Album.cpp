// ============================================================================
// Album.cpp - Implémentation de la classe Album
// ============================================================================

#include "Album.h"

// ============================================================================
// CONSTRUCTEUR PAR DEFAUT
// ============================================================================
Album::Album() : Livre() {
    typeIllustration = DESSINS;
}

// ============================================================================
// CONSTRUCTEUR AVEC PARAMETRES
// ============================================================================
Album::Album(string code, string auteur, string titre, string editeur,
             string isbn, Public publicCible, TypeIllustration typeIllustration)
    : Livre(code, auteur, titre, editeur, isbn, publicCible) {
    
    this->typeIllustration = typeIllustration;
}

// ============================================================================
// DESTRUCTEUR
// ============================================================================
Album::~Album() {
    // Destructeur de Livre appelé automatiquement
}

// ============================================================================
// typeIllustrationToString() - Convertit l'enum en texte
// ============================================================================
string Album::typeIllustrationToString() const {
    switch(typeIllustration) {
        case PHOTOS:            return "Photos";
        case DESSINS:           return "Dessins";
        case PHOTOS_ET_DESSINS: return "Photos et Dessins";
        default:                return "Inconnu";
    }
}

// ============================================================================
// afficher() - Affichage spécifique pour un album
// ============================================================================
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

// ============================================================================
// getType()
// ============================================================================
string Album::getType() const {
    return "Album";
}

// ============================================================================
// GETTER
// ============================================================================
TypeIllustration Album::getTypeIllustration() const {
    return typeIllustration;
}

// ============================================================================
// SETTER
// ============================================================================
void Album::setTypeIllustration(TypeIllustration nouveauType) {
    typeIllustration = nouveauType;
}