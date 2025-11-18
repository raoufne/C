#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
#include <string>
using namespace std;

class Personne {
protected:
    string nom;
    string prenom;
    string adresse;
    string telephone;

public:
    Personne(string nom="", string prenom="", string adresse="", string telephone="");

    string getNom() const;
    string getPrenom() const;
    string getAdresse() const;
    string getTelephone() const;

    void setNom(string n);
    void setPrenom(string p);
    void setAdresse(string a);
    void setTelephone(string t);

    virtual void affiche() const;
    virtual ~Personne() {}
    virtual float calculSalaire() const;
};

#endif
