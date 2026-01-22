#ifndef ROMAN_H
#define ROMAN_H

#include "Livre.h"  

enum GenreRoman {
    LITTERATURE
    ,ROMAN_NOIR
    ,ROMAN_POLICIER
    ,ROMAN_ANIMALIER
    ,ROMAN_AMOUR
    ,ROMAN_MOEURS
    ,ROMAN_GOTHIQUE
    ,ROMAN_COURTOIS
    ,ROMAN_EPISTOLAIRE
    ,ROMAN_FEUILLETON
    ,ROMAN_GRAPHIQUE
    ,ROMAN_HISTORIQUE
    ,ROMAN_PHOTO
    ,ROMAN_PICARESQUE
    ,ROMAN_MEMOIRES
    ,ROMAN_POPULAIRE
    ,ROMAN_AVENTURES
    ,ROMAN_ANTICIPATION
    ,ROMAN_ESPIONNAGE
    ,ROMAN_APPRENTISSAGE
    ,ROMAN_CHEVALERIE
    ,ROMAN_AUTOBIOGRAPHIQUE
    ,NOUVEAU_ROMAN
    ,CONTE
    ,NOUVELLE
    ,AUTRE_GENRE
};  

class Roman : public Livre {

private:
    GenreRoman genreRoman;  

public:

    Roman();
    
    Roman(string code, string auteur, string titre, string editeur,
          string isbn, Public publicCible, GenreRoman genreRoman);

    ~Roman();

    void afficher() const override;

    string getType() const override;

    GenreRoman getGenreRoman() const;

    string genreRomanToString() const;
};

#endif