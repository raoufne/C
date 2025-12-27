// ============================================================================
// Livre.h - Classe de base pour tous les types de livres
// ============================================================================
// C'est une CLASSE ABSTRAITE (on ne peut pas créer d'objet Livre directement)
// Les classes Roman, BD, Poesie, Theatre, Album vont HERITER de cette classe
// ============================================================================

#ifndef LIVRE_H   // Protection contre les inclusions multiples
#define LIVRE_H   // Si LIVRE_H n'est pas défini, on le définit

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// ENUM : Pour le public cible du livre
// ============================================================================
// Un enum c'est une liste de valeurs possibles (comme un choix multiple)
enum Public {
    ADULTE,
    ADOS,
    JEUNESSE,
    TOUT_PUBLIC
};

// ============================================================================
// ENUM : Pour l'état du livre
// ============================================================================
enum Etat {
    LIBRE,      // Disponible pour emprunt
    EMPRUNTE,   // Emprunté par un adhérent
    PRETE       // Prêté à une autre bibliothèque
};

// ============================================================================
// CLASSE LIVRE
// ============================================================================
class Livre {

// ----------------------------------------------------------------------------
// PROTECTED : accessible par cette classe ET ses classes filles
// ----------------------------------------------------------------------------
protected:
    string code;        // Code unique (ex: "ROM001")
    string auteur;      // Nom de l'auteur
    string titre;       // Titre du livre
    string editeur;     // Maison d'édition
    string isbn;        // Numéro ISBN
    Public publicCible; // Pour qui ? (adulte, ados, etc.)
    Etat etat;          // Disponible ou pas ?

    // ========================================================================
    // MEMBRE STATIQUE (variable de classe)
    // ========================================================================
    // "static" = partagé par TOUS les objets de la classe
    // Ici on compte combien de livres existent au total
    static int nombreTotalLivres;

// ----------------------------------------------------------------------------
// PUBLIC : accessible de partout
// ----------------------------------------------------------------------------
public:
    // ========================================================================
    // CONSTRUCTEURS
    // ========================================================================
    Livre();  // Constructeur par défaut
    
    Livre(string code, string auteur, string titre, 
          string editeur, string isbn, Public publicCible);

    // ========================================================================
    // DESTRUCTEUR VIRTUEL
    // ========================================================================
    // "virtual" = OBLIGATOIRE pour une classe mère
    // Sinon le destructeur des classes filles ne sera pas appelé !
    virtual ~Livre();

    // ========================================================================
    // METHODE VIRTUELLE PURE (= 0)
    // ========================================================================
    // "= 0" signifie : pas de code ici, les classes filles DOIVENT la définir
    // C'est ça qui rend la classe ABSTRAITE
    virtual void afficher() const = 0;

    // ========================================================================
    // METHODE VIRTUELLE (non pure)
    // ========================================================================
    // Les classes filles PEUVENT la redéfinir (mais pas obligé)
    virtual string getType() const;

    // ========================================================================
    // GETTERS (accesseurs) - pour lire les attributs
    // ========================================================================
    // "const" à la fin = cette méthode ne modifie pas l'objet
    string getCode() const;
    string getAuteur() const;
    string getTitre() const;
    string getEditeur() const;
    string getIsbn() const;
    Public getPublicCible() const;
    Etat getEtat() const;

    // ========================================================================
    // SETTERS (mutateurs) - pour modifier les attributs
    // ========================================================================
    void setEtat(Etat nouvelEtat);

    // ========================================================================
    // METHODE STATIQUE
    // ========================================================================
    // Peut être appelée SANS créer d'objet : Livre::getNombreTotalLivres()
    static int getNombreTotalLivres();

    // ========================================================================
    // METHODES UTILITAIRES
    // ========================================================================
    string etatToString() const;    // Convertit l'état en texte
    string publicToString() const;  // Convertit le public en texte
    bool estDisponible() const;     // Retourne true si état == LIBRE

    // ========================================================================
    // REDEFINITION D'OPERATEUR ==
    // ========================================================================
    // Permet d'écrire : if (livre1 == livre2)
    bool operator==(const Livre& autre) const;

    // ========================================================================
    // FONCTION AMIE
    // ========================================================================
    // "friend" = cette fonction peut accéder aux attributs privés/protégés
    // Permet d'écrire : cout << monLivre;
    friend ostream& operator<<(ostream& os, const Livre& livre);
};

#endif // LIVRE_H