#ifndef ADHERENT_H
#define ADHERENT_H

#include <iostream>
#include <string>
#include "Livre.h"
#include "ListeChainee.h"
#include "Exceptions.h"
using namespace std;

class Bibliotheque;

class Adherent {

private:
    string nom;
    string prenom;
    string adresse;
    string numeroAdherent;              
    Bibliotheque* bibliotheque;         
    ListeChainee<Livre*> livresEmpruntes;  
    int nombreMaxEmprunts;             

    static int compteurAdherents;

public:
    Adherent();
    
    Adherent(string nom, string prenom, string adresse, 
             Bibliotheque* biblio, int maxEmprunts = 3);

    ~Adherent();

    void emprunterLivre(const string& codeLivre);

    void rendreLivre(Livre* livre);

    void afficher() const;
    void afficherLivresEmpruntes() const;

    string getNom() const;
    string getPrenom() const;
    string getAdresse() const;
    string getNumeroAdherent() const;
    int getNombreEmprunts() const;
    int getNombreMaxEmprunts() const;

    void setBibliotheque(Bibliotheque* nouvelleBiblio);

    static int getCompteurAdherents();

    bool operator==(const Adherent& autre) const;

    friend ostream& operator<<(ostream& os, const Adherent& adherent);
};

#endif