// ============================================================================
// Adherent.h - Classe Adherent
// ============================================================================
// Un adhérent est une personne inscrite à une bibliothèque.
// Il peut emprunter des livres (avec une limite).
// ============================================================================

#ifndef ADHERENT_H
#define ADHERENT_H

#include <iostream>
#include <string>
#include "Livre.h"
#include "ListeChainee.h"
#include "Exceptions.h"
using namespace std;

// ============================================================================
// DECLARATION ANTICIPEE (Forward Declaration)
// ============================================================================
// On dit au compilateur "la classe Bibliotheque existe"
// sans inclure tout le fichier Bibliotheque.h
// Cela évite les inclusions circulaires (A inclut B qui inclut A)
class Bibliotheque;

// ============================================================================
// CLASSE ADHERENT
// ============================================================================

class Adherent {

private:
    string nom;
    string prenom;
    string adresse;
    string numeroAdherent;              // Numéro unique (ex: "ADH001")
    Bibliotheque* bibliotheque;         // Pointeur vers sa bibliothèque
    ListeChainee<Livre*> livresEmpruntes;  // Liste des livres empruntés
    int nombreMaxEmprunts;              // Limite d'emprunts autorisée

    // ========================================================================
    // MEMBRE STATIQUE
    // ========================================================================
    // Compteur pour générer des numéros uniques
    static int compteurAdherents;

public:
    // ========================================================================
    // CONSTRUCTEURS
    // ========================================================================
    Adherent();
    
    Adherent(string nom, string prenom, string adresse, 
             Bibliotheque* biblio, int maxEmprunts = 3);

    // ========================================================================
    // DESTRUCTEUR
    // ========================================================================
    ~Adherent();

    // ========================================================================
    // emprunterLivre() - Emprunte un livre
    // ========================================================================
    // Peut lancer : LimiteEmpruntException, LivreNonDisponibleException
    void emprunterLivre(const string& codeLivre);

    // ========================================================================
    // rendreLivre() - Rend un livre emprunté
    // ========================================================================
    // Peut lancer : LivreNonEmprunteException
    void rendreLivre(Livre* livre);

    // ========================================================================
    // AFFICHAGE
    // ========================================================================
    void afficher() const;
    void afficherLivresEmpruntes() const;

    // ========================================================================
    // GETTERS
    // ========================================================================
    string getNom() const;
    string getPrenom() const;
    string getAdresse() const;
    string getNumeroAdherent() const;
    // Bibliotheque* getBibliotheque() const;
    int getNombreEmprunts() const;
    int getNombreMaxEmprunts() const;
    // ListeChainee<Livre*>& getLivresEmpruntes();

    // ========================================================================
    // SETTERS
    // ========================================================================
    // void setNom(string nouveauNom);
    // void setPrenom(string nouveauPrenom);
    // void setAdresse(string nouvelleAdresse);
    void setBibliotheque(Bibliotheque* nouvelleBiblio);
    // void setNombreMaxEmprunts(int nouveauMax);

    // ========================================================================
    // METHODE STATIQUE
    // ========================================================================
    static int getCompteurAdherents();

    // ========================================================================
    // REDEFINITION OPERATEUR ==
    // ========================================================================
    // Deux adhérents sont égaux s'ils ont le même numéro
    bool operator==(const Adherent& autre) const;

    // ========================================================================
    // FONCTION AMIE - pour cout << adherent
    // ========================================================================
    friend ostream& operator<<(ostream& os, const Adherent& adherent);
};

#endif // ADHERENT_H