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
    genreRoman = AUTRE_GENRE;
}

// ============================================================================
// CONSTRUCTEUR AVEC PARAMETRES
// ============================================================================
// On passe les paramètres de Livre au constructeur de Livre
// Puis on initialise l'attribut spécifique au Roman

Roman::Roman(string code, string auteur, string titre, string editeur,
             string isbn, Public publicCible, GenreRoman genreRoman)
    : Livre(code, auteur, titre, editeur, isbn, publicCible) {
    
    // Les attributs de Livre sont déjà initialisés par le constructeur Livre()
    // On initialise seulement l'attribut propre à Roman
    this->genreRoman = genreRoman;
}

// ============================================================================
// DESTRUCTEUR
// ============================================================================
Roman::~Roman() {
    // Le destructeur de Livre sera appelé AUTOMATIQUEMENT après
    // grâce au mot-clé "virtual" dans la classe mère
}

// ============================================================================
// genreRomanToString() - Convertit l'enum en texte lisible
// ============================================================================
string Roman::genreRomanToString() const {
    switch(genreRoman) {
        case LITTERATURE:           return "Littérature";
        case ROMAN_NOIR:            return "Roman Noir";
        case ROMAN_POLICIER:        return "Roman Policier";
        case ROMAN_ANIMALIER:       return "Roman Animalier";
        case ROMAN_AMOUR:           return "Roman d'Amour";
        case ROMAN_MOEURS:          return "Roman de Mœurs";
        case ROMAN_GOTHIQUE:        return "Roman Gothique";
        case ROMAN_COURTOIS:        return "Roman de Courtoisie";
        case ROMAN_EPISTOLAIRE:     return "Roman Épistolaire";
        case ROMAN_FEUILLETON:      return "Roman Feuilleton";
        case ROMAN_GRAPHIQUE:       return "Roman Graphique";
        case ROMAN_HISTORIQUE:      return "Roman Historique";
        case ROMAN_PHOTO:           return "Roman Photo";
        case ROMAN_PICARESQUE:      return "Roman Picaresque";
        case ROMAN_MEMOIRES:        return "Memoires Romanesques";
        case ROMAN_POPULAIRE:       return "Roman Populaire";
        case ROMAN_AVENTURES:       return "Aventures Romanesques";
        case ROMAN_ANTICIPATION:    return "Science-Fiction Romanesque";
        case ROMAN_ESPIONNAGE:      return "Espionnage Romanesque";
        case ROMAN_APPRENTISSAGE:   return "Apprentissage Romanesque";
        case ROMAN_CHEVALERIE:      return "Roman de Chevalerie";
        case ROMAN_AUTOBIOGRAPHIQUE:return "Roman Autobiographique";
        case NOUVEAU_ROMAN:        return "Nouveau Roman";
        case CONTE:                 return "Conte";
        case NOUVELLE:              return "Nouvelle";
        case AUTRE_GENRE:          return "Autre Genre";
        default:            return "Inconnu";
    }
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
    cout << "Genre:   " << genreRomanToString() << endl;  // Attribut spécifique au Roman
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

// // ============================================================================
// // GETTER pour le genre
// // ============================================================================
GenreRoman Roman::getGenreRoman() const {
    return genreRoman;
}

// // ============================================================================
// // SETTER pour le genre
// // ============================================================================
// void Roman::setGenreRoman(GenreRoman nouveauGenreRoman) {
//     genreRoman = nouveauGenreRoman;
// }