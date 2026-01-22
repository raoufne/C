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

class Adherent;

class Bibliotheque {

private:
    string nom;
    string adresse;
    string code;                        
    ListeChainee<Livre*> livres;        
    ListeChainee<Adherent*> adherents;  

public:
    Bibliotheque();
    Bibliotheque(string nom, string adresse, string code);

    ~Bibliotheque();

    void afficherTousLesLivres() const;
    void afficherLivresParCategorie(const string& categorie) const;
    void afficherLivresDisponibles() const;

    Livre* rechercherLivreParCode(const string& codeLivre) const;
    Livre* rechercherLivreParISBN(const string& isbn) const;

    void acheterLivre(Livre* nouveauLivre);
    void supprimerLivre(const string& codeLivre);  

    void inscrireAdherent(Adherent* nouvelAdherent);
    void desinscrireAdherent(const string& numeroAdherent);
    Adherent* rechercherAdherent(const string& numeroAdherent) const;
    void afficherTousLesAdherents() const;

    bool demanderLivre(Bibliotheque* autreBiblio, const string& isbn);
    
    Livre* preterLivre(const string& isbn);

    void rendreLivresPretes(Bibliotheque* proprietaire);

    void afficher() const;

    string getNom() const;
    string getAdresse() const;
    string getCode() const;
    ListeChainee<Livre*>& getLivres();
    ListeChainee<Adherent*>& getAdherents();

    friend ostream& operator<<(ostream& os, const Bibliotheque& biblio);
};

#endif