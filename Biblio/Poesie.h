// ============================================================================
// Poesie.h - Classe Poesie (hérite de Livre)
// ============================================================================
// Un recueil de poésie est un Livre avec un indicateur :
// vers, prose, ou les deux
// ============================================================================

#ifndef POESIE_H
#define POESIE_H

#include "Livre.h"

// ============================================================================
// ENUM : Type de poésie
// ============================================================================
enum TypePoesie {
    VERS,
    PROSE,
    VERS_ET_PROSE
};

// ============================================================================
// CLASSE POESIE - hérite de Livre
// ============================================================================

class Poesie : public Livre {

private:
    TypePoesie typePoesie;  // Vers, prose ou les deux

public:
    // ========================================================================
    // CONSTRUCTEURS
    // ========================================================================
    Poesie();
    
    Poesie(string code, string auteur, string titre, string editeur,
           string isbn, Public publicCible, TypePoesie typePoesie);

    // ========================================================================
    // DESTRUCTEUR
    // ========================================================================
    ~Poesie();

    // ========================================================================
    // REDEFINITION DES METHODES VIRTUELLES
    // ========================================================================
    void afficher() const override;
    string getType() const override;

    // // ========================================================================
    // // GETTER / SETTER spécifique
    // // ========================================================================
    TypePoesie getTypePoesie() const;
    // void setTypePoesie(TypePoesie nouveauType);
    
    // Méthode utilitaire pour convertir l'enum en string
    string typePoesieToString() const;
};

#endif // POESIE_H