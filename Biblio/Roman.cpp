#include "Roman.h"

Roman::Roman() : Livre() {
    genreRoman = AUTRE_GENRE;
}

Roman::Roman(string code, string auteur, string titre, string editeur,
             string isbn, Public publicCible, GenreRoman genreRoman)
    : Livre(code, auteur, titre, editeur, isbn, publicCible) {

    this->genreRoman = genreRoman;
}

Roman::~Roman() {
}

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

void Roman::afficher() const {
    cout << "======== ROMAN ========" << endl;
    cout << "Code:    " << code << endl;
    cout << "Titre:   " << titre << endl;
    cout << "Auteur:  " << auteur << endl;
    cout << "Editeur: " << editeur << endl;
    cout << "ISBN:    " << isbn << endl;
    cout << "Genre:   " << genreRomanToString() << endl;
    cout << "Public:  " << publicToString() << endl;
    cout << "Etat:    " << etatToString() << endl;
    cout << "========================" << endl;
}

string Roman::getType() const {
    return "Roman";
}

GenreRoman Roman::getGenreRoman() const {
    return genreRoman;
}