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

class Roman : public Livre {

// ----------------------------------------------------------------------------
// PRIVATE : accessible uniquement dans cette classe
// ----------------------------------------------------------------------------
private:
    string genre;  // Ex: "Policier", "Aventure", "Science-Fiction"...

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
          string isbn, Public publicCible, string genre);

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

    // ========================================================================
    // GETTER / SETTER spécifique au Roman
    // ========================================================================
    string getGenre() const;
    void setGenre(string nouveauGenre);
};

#endif // ROMAN_H