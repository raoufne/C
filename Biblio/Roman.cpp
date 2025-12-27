// ============================================================================
// Roman.cpp - Implémentation de la classe Roman
// ============================================================================

#include "Roman.h"

// ============================================================================
// CONSTRUCTEUR PAR DEFAUT
// ============================================================================
// On appelle d'abord le constructeur de la classe mère avec : Livre()
// C'est la "liste d'initialisation" (après les deux-points)

Roman::Roman() : Livre() {
    genre = "Non specifie";
}

// ============================================================================
// CONSTRUCTEUR AVEC PARAMETRES
// ============================================================================
// On passe les paramètres de Livre au constructeur de Livre
// Puis on initialise l'attribut spécifique au Roman

Roman::Roman(string code, string auteur, string titre, string editeur,
             string isbn, Public publicCible, string genre)
    : Livre(code, auteur, titre, editeur, isbn, publicCible) {
    
    // Les attributs de Livre sont déjà initialisés par le constructeur Livre()
    // On initialise seulement l'attribut propre à Roman
    this->genre = genre;
}

// ============================================================================
// DESTRUCTEUR
// ============================================================================
Roman::~Roman() {
    // Le destructeur de Livre sera appelé AUTOMATIQUEMENT après
    // grâce au mot-clé "virtual" dans la classe mère
}

// ============================================================================
// afficher() - REDEFINITION de la méthode virtuelle pure
// ============================================================================
// C'est ici qu'on écrit le code pour afficher un Roman
// On a accès aux attributs "protected" de Livre (code, titre, auteur, etc.)

void Roman::afficher() const {
    cout << "======== ROMAN ========" << endl;
    cout << "Code:    " << code << endl;
    cout << "Titre:   " << titre << endl;
    cout << "Auteur:  " << auteur << endl;
    cout << "Editeur: " << editeur << endl;
    cout << "ISBN:    " << isbn << endl;
    cout << "Genre:   " << genre << endl;  // Attribut spécifique au Roman
    cout << "Public:  " << publicToString() << endl;
    cout << "Etat:    " << etatToString() << endl;
    cout << "========================" << endl;
}

// ============================================================================
// getType() - Retourne "Roman"
// ============================================================================
string Roman::getType() const {
    return "Roman";
}

// ============================================================================
// GETTER pour le genre
// ============================================================================
string Roman::getGenre() const {
    return genre;
}

// ============================================================================
// SETTER pour le genre
// ============================================================================
void Roman::setGenre(string nouveauGenre) {
    genre = nouveauGenre;
}