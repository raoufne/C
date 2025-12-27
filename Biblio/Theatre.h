// ============================================================================
// Theatre.h - Classe Theatre (hérite de Livre)
// ============================================================================
// Une pièce de théâtre est un Livre dont on connaît le siècle
// Ex: 17 pour le XVIIe siècle (Molière, Racine, Corneille)
// ============================================================================

#ifndef THEATRE_H
#define THEATRE_H

#include "Livre.h"

// ============================================================================
// CLASSE THEATRE - hérite de Livre
// ============================================================================

class Theatre : public Livre {

private:
    int siecle;  // Ex: 17 pour XVIIe, 20 pour XXe siècle

public:
    // ========================================================================
    // CONSTRUCTEURS
    // ========================================================================
    Theatre();
    
    Theatre(string code, string auteur, string titre, string editeur,
            string isbn, Public publicCible, int siecle);

    // ========================================================================
    // DESTRUCTEUR
    // ========================================================================
    ~Theatre();

    // ========================================================================
    // REDEFINITION DES METHODES VIRTUELLES
    // ========================================================================
    void afficher() const override;
    string getType() const override;

    // ========================================================================
    // GETTER / SETTER spécifique
    // ========================================================================
    int getSiecle() const;
    void setSiecle(int nouveauSiecle);
    
    // Méthode utilitaire pour afficher le siècle en chiffres romains
    string siecleToString() const;
};

#endif // THEATRE_H