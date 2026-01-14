// ============================================================================
// Album.h - Classe Album (hérite de Livre)
// ============================================================================
// Un album est un Livre avec un type d'illustration :
// photos, dessins, ou les deux
// ============================================================================

#ifndef ALBUM_H
#define ALBUM_H

#include "Livre.h"

// ============================================================================
// ENUM : Type d'illustration
// ============================================================================
enum TypeIllustration {
    PHOTOS,
    DESSINS,
    PHOTOS_ET_DESSINS
};

// ============================================================================
// CLASSE ALBUM - hérite de Livre
// ============================================================================

class Album : public Livre {

private:
    TypeIllustration typeIllustration;

public:
    // ========================================================================
    // CONSTRUCTEURS
    // ========================================================================
    Album();
    
    Album(string code, string auteur, string titre, string editeur,
          string isbn, Public publicCible, TypeIllustration typeIllustration);

    // ========================================================================
    // DESTRUCTEUR
    // ========================================================================
    ~Album();

    // ========================================================================
    // REDEFINITION DES METHODES VIRTUELLES
    // ========================================================================
    void afficher() const override;
    string getType() const override;

    // // ========================================================================
    // // GETTER / SETTER spécifique
    // // ========================================================================
    TypeIllustration getTypeIllustration() const;
    // void setTypeIllustration(TypeIllustration nouveauType);
    
    // Méthode utilitaire
    string typeIllustrationToString() const;
};

#endif // ALBUM_H