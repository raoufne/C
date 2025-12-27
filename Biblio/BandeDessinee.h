// ============================================================================
// BandeDessinee.h - Classe BandeDessinee (hérite de Livre)
// ============================================================================
// Une BD est un Livre avec un attribut en plus : le dessinateur
// (Le scénariste est stocké dans "auteur" hérité de Livre)
// ============================================================================

#ifndef BANDEDESSINEE_H
#define BANDEDESSINEE_H

#include "Livre.h"

// ============================================================================
// CLASSE BANDEDESSINEE - hérite de Livre
// ============================================================================

class BandeDessinee : public Livre {

private:
    string dessinateur;  // Nom du dessinateur (peut être différent de l'auteur)

public:
    // ========================================================================
    // CONSTRUCTEURS
    // ========================================================================
    BandeDessinee();
    
    BandeDessinee(string code, string auteur, string titre, string editeur,
                  string isbn, Public publicCible, string dessinateur);

    // ========================================================================
    // DESTRUCTEUR
    // ========================================================================
    ~BandeDessinee();

    // ========================================================================
    // REDEFINITION DES METHODES VIRTUELLES
    // ========================================================================
    void afficher() const override;
    string getType() const override;

    // ========================================================================
    // GETTER / SETTER spécifique
    // ========================================================================
    string getDessinateur() const;
    void setDessinateur(string nouveauDessinateur);
};

#endif // BANDEDESSINEE_H