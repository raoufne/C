// ============================================================================
// Poesie.cpp - Implémentation de la classe Poesie
// ============================================================================

#include "Poesie.h"

// ============================================================================
// CONSTRUCTEUR PAR DEFAUT
// ============================================================================
Poesie::Poesie() : Livre() {
    typePoesie = VERS;
}

// ============================================================================
// CONSTRUCTEUR AVEC PARAMETRES
// ============================================================================
Poesie::Poesie(string code, string auteur, string titre, string editeur,
               string isbn, Public publicCible, TypePoesie typePoesie)
    : Livre(code, auteur, titre, editeur, isbn, publicCible) {
    
    this->typePoesie = typePoesie;
}

// ============================================================================
// DESTRUCTEUR
// ============================================================================
Poesie::~Poesie() {
    // Destructeur de Livre appelé automatiquement
}

// ============================================================================
// typePoesieToString() - Convertit l'enum en texte lisible
// ============================================================================
string Poesie::typePoesieToString() const {
    switch(typePoesie) {
        case VERS:          return "Vers";
        case PROSE:         return "Prose";
        case VERS_ET_PROSE: return "Vers et Prose";
        default:            return "Inconnu";
    }
}

// ============================================================================
// afficher() - Affichage spécifique pour un recueil de poésie
// ============================================================================
void Poesie::afficher() const {
    cout << "======== POESIE ========" << endl;
    cout << "Code:    " << code << endl;
    cout << "Titre:   " << titre << endl;
    cout << "Auteur:  " << auteur << endl;
    cout << "Editeur: " << editeur << endl;
    cout << "ISBN:    " << isbn << endl;
    cout << "Type:    " << typePoesieToString() << endl;  // Attribut spécifique
    cout << "Public:  " << publicToString() << endl;
    cout << "Etat:    " << etatToString() << endl;
    cout << "========================" << endl;
}

// ============================================================================
// getType()
// ============================================================================
string Poesie::getType() const {
    return "Poesie";
}

// // ============================================================================
// // GETTER
// // ============================================================================
TypePoesie Poesie::getTypePoesie() const {
    return typePoesie;
}

// // ============================================================================
// // SETTER
// // ============================================================================
// void Poesie::setTypePoesie(TypePoesie nouveauType) {
//     typePoesie = nouveauType;
// }