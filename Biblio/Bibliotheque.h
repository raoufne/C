// ============================================================================
// Bibliotheque.h - Classe Bibliotheque
// ============================================================================
// Une bibliothèque contient des livres et des adhérents.
// Elle permet d'acheter, supprimer, prêter des livres.
// ============================================================================

#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <iostream>
#include <string>
#include "Livre.h"
#include "Roman.h"
#include "BandeDessinee.h"
#include "Poesie.h"
#include "Theatre.h"
#include "Album.h"
#include "ListeChainee.h"
#include "Exceptions.h"
using namespace std;

// Déclaration anticipée
class Adherent;

// ============================================================================
// CLASSE BIBLIOTHEQUE
// ============================================================================

class Bibliotheque {

private:
    string nom;
    string adresse;
    string code;                        // Code unique (ex: "BIB001")
    ListeChainee<Livre*> livres;        // Liste des livres
    ListeChainee<Adherent*> adherents;  // Liste des adhérents

    // ========================================================================
    // MEMBRE STATIQUE
    // ========================================================================
    static int nombreTotalBibliotheques;

public:
    // ========================================================================
    // CONSTRUCTEURS
    // ========================================================================
    Bibliotheque();
    Bibliotheque(string nom, string adresse, string code);

    // ========================================================================
    // DESTRUCTEUR
    // ========================================================================
    ~Bibliotheque();

    // ========================================================================
    // AFFICHAGE DES LIVRES
    // ========================================================================
    void afficherTousLesLivres() const;
    void afficherLivresParCategorie(const string& categorie) const;
    void afficherLivresDisponibles() const;

    // ========================================================================
    // RECHERCHE DE LIVRES
    // ========================================================================
    Livre* rechercherLivreParCode(const string& codeLivre) const;
    Livre* rechercherLivreParISBN(const string& isbn) const;

    // ========================================================================
    // GESTION DES LIVRES
    // ========================================================================
    void acheterLivre(Livre* nouveauLivre);
    void supprimerLivre(const string& codeLivre);  // Perte ou mise au pilon

    // ========================================================================
    // GESTION DES ADHERENTS
    // ========================================================================
    void inscrireAdherent(Adherent* nouvelAdherent);
    void desinscrireAdherent(const string& numeroAdherent);
    Adherent* rechercherAdherent(const string& numeroAdherent) const;
    void afficherTousLesAdherents() const;

    // ========================================================================
    // ECHANGES ENTRE BIBLIOTHEQUES
    // ========================================================================
    // Demande un livre à une autre bibliothèque (par ISBN)
    bool demanderLivre(Bibliotheque* autreBiblio, const string& isbn);
    
    // Prête un livre à une autre bibliothèque
    Livre* preterLivre(const string& isbn);
    
    // Rend les livres prêtés qui ne sont plus empruntés
    void rendreLivresPretes(Bibliotheque* proprietaire);

    // ========================================================================
    // AFFICHAGE
    // ========================================================================
    void afficher() const;

    // ========================================================================
    // GETTERS
    // ========================================================================
    string getNom() const;
    string getAdresse() const;
    string getCode() const;
    int getNombreLivres() const;
    int getNombreAdherents() const;
    ListeChainee<Livre*>& getLivres();
    ListeChainee<Adherent*>& getAdherents();

    // ========================================================================
    // SETTERS
    // ========================================================================
    void setNom(string nouveauNom);
    void setAdresse(string nouvelleAdresse);

    // ========================================================================
    // METHODE STATIQUE
    // ========================================================================
    static int getNombreTotalBibliotheques();

    // ========================================================================
    // OPERATEUR ==
    // ========================================================================
    bool operator==(const Bibliotheque& autre) const;

    // ========================================================================
    // FONCTION AMIE
    // ========================================================================
    friend ostream& operator<<(ostream& os, const Bibliotheque& biblio);
};

#endif // BIBLIOTHEQUE_H