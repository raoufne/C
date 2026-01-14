// ============================================================================
// Theatre.cpp - Implémentation de la classe Theatre
// ============================================================================

#include "Theatre.h"

// ============================================================================
// CONSTRUCTEUR PAR DEFAUT
// ============================================================================
Theatre::Theatre() : Livre() {
    siecle = 21;  // Par défaut, XXIe siècle
}

// ============================================================================
// CONSTRUCTEUR AVEC PARAMETRES
// ============================================================================
Theatre::Theatre(string code, string auteur, string titre, string editeur,
                 string isbn, Public publicCible, int siecle)
    : Livre(code, auteur, titre, editeur, isbn, publicCible) {
    
    this->siecle = siecle;
}

// ============================================================================
// DESTRUCTEUR
// ============================================================================
Theatre::~Theatre() {
    // Destructeur de Livre appelé automatiquement
}

// ============================================================================
// siecleToString() - Convertit le siècle en chiffres romains
// ============================================================================
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

// ============================================================================
// afficher() - Affichage spécifique pour une pièce de théâtre
// ============================================================================
void Theatre::afficher() const {
    cout << "======== THEATRE ========" << endl;
    cout << "Code:    " << code << endl;
    cout << "Titre:   " << titre << endl;
    cout << "Auteur:  " << auteur << endl;
    cout << "Editeur: " << editeur << endl;
    cout << "ISBN:    " << isbn << endl;
    cout << "Siecle:  " << siecleToString() << endl;  // Attribut spécifique
    cout << "Public:  " << publicToString() << endl;
    cout << "Etat:    " << etatToString() << endl;
    cout << "=========================" << endl;
}

// ============================================================================
// getType()
// ============================================================================
string Theatre::getType() const {
    return "Theatre";
}

// // ============================================================================
// // GETTER
// // ============================================================================
int Theatre::getSiecle() const {
    return siecle;
}

// // ============================================================================
// // SETTER
// // ============================================================================
// void Theatre::setSiecle(int nouveauSiecle) {
//     siecle = nouveauSiecle;
// }