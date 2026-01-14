// ============================================================================
// Roman.h - Classe Roman (hérite de Livre)
// ============================================================================
// CONCEPT : HERITAGE
// Un Roman EST UN Livre avec un attribut en plus : le genre
// ============================================================================

#ifndef ROMAN_H
#define ROMAN_H

#include "Livre.h"  // On inclut la classe mère

// ============================================================================
// CLASSE ROMAN - hérite de Livre
// ============================================================================
// Syntaxe : class Fille : public Mere
// "public" = les membres publics de Livre restent publics dans Roman
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

// ----------------------------------------------------------------------------
// PRIVATE : accessible uniquement dans cette classe
// ----------------------------------------------------------------------------
private:
    GenreRoman genreRoman;  // Ex: "Policier", "Aventure", "Science-Fiction"...

// ----------------------------------------------------------------------------
// PUBLIC
// ----------------------------------------------------------------------------
public:
    // ========================================================================
    // CONSTRUCTEURS
    // ========================================================================
    Roman();
    
    // Constructeur avec tous les paramètres (ceux de Livre + genre)
    Roman(string code, string auteur, string titre, string editeur,
          string isbn, Public publicCible, GenreRoman genreRoman);

    // ========================================================================
    // DESTRUCTEUR
    // ========================================================================
    ~Roman();

    // ========================================================================
    // REDEFINITION DE METHODE VIRTUELLE PURE
    // ========================================================================
    // On DOIT redéfinir afficher() car elle est "= 0" dans Livre
    // "override" = mot-clé C++11 qui vérifie qu'on redéfinit bien une méthode virtuelle
    void afficher() const override;

    // ========================================================================
    // REDEFINITION DE getType()
    // ========================================================================
    string getType() const override;

    // // ========================================================================
    // // GETTER / SETTER spécifique au Roman
    // // ========================================================================
    GenreRoman getGenreRoman() const;
    // void setGenreRoman(GenreRoman nouveauGenreRoman);

    // Méthode utilitaire pour convertir l'enum en string
    string genreRomanToString() const;
};

#endif // ROMAN_H