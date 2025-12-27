// ============================================================================
// BandeDessinee.cpp - Implémentation de la classe BandeDessinee
// ============================================================================

#include "BandeDessinee.h"

// ============================================================================
// CONSTRUCTEUR PAR DEFAUT
// ============================================================================
BandeDessinee::BandeDessinee() : Livre() {
    dessinateur = "Inconnu";
}

// ============================================================================
// CONSTRUCTEUR AVEC PARAMETRES
// ============================================================================
BandeDessinee::BandeDessinee(string code, string auteur, string titre, 
                             string editeur, string isbn, Public publicCible, 
                             string dessinateur)
    : Livre(code, auteur, titre, editeur, isbn, publicCible) {
    
    this->dessinateur = dessinateur;
}

// ============================================================================
// DESTRUCTEUR
// ============================================================================
BandeDessinee::~BandeDessinee() {
    // Destructeur de Livre appelé automatiquement
}

// ============================================================================
// afficher() - Affichage spécifique pour une BD
// ============================================================================
void BandeDessinee::afficher() const {
    cout << "===== BANDE DESSINEE =====" << endl;
    cout << "Code:       " << code << endl;
    cout << "Titre:      " << titre << endl;
    cout << "Scenariste: " << auteur << endl;      // L'auteur = scénariste pour une BD
    cout << "Dessinateur:" << dessinateur << endl;  // Attribut spécifique
    cout << "Editeur:    " << editeur << endl;
    cout << "ISBN:       " << isbn << endl;
    cout << "Public:     " << publicToString() << endl;
    cout << "Etat:       " << etatToString() << endl;
    cout << "==========================" << endl;
}

// ============================================================================
// getType()
// ============================================================================
string BandeDessinee::getType() const {
    return "BandeDessinee";
}

// ============================================================================
// GETTER
// ============================================================================
string BandeDessinee::getDessinateur() const {
    return dessinateur;
}

// ============================================================================
// SETTER
// ============================================================================
void BandeDessinee::setDessinateur(string nouveauDessinateur) {
    dessinateur = nouveauDessinateur;
}