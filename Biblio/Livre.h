#ifndef LIVRE_H   
#define LIVRE_H 

#include <iostream>
#include <string>
using namespace std;

enum Public {
    ADULTE,
    ADOS,
    JEUNESSE,
    TOUT_PUBLIC
};
enum Etat {
    LIBRE,      
    EMPRUNTE,   
    PRETE       
};

class Livre {
protected:
    string code;        
    string auteur;      
    string titre;       
    string editeur;     
    string isbn;        
    Public publicCible; 
    Etat etat;          

    static int nombreTotalLivres;

public:
    Livre();  
    Livre(string code, string auteur, string titre, 
          string editeur, string isbn, Public publicCible);

    virtual ~Livre();

    virtual void afficher() const = 0;

    virtual string getType() const;

    string getCode() const;
    string getAuteur() const;
    string getTitre() const;
    string getEditeur() const;
    string getIsbn() const;
    Public getPublicCible() const;
    Etat getEtat() const;

    void setEtat(Etat nouvelEtat);

    static int getNombreTotalLivres();

    string etatToString() const;   
    string publicToString() const; 
    bool estDisponible() const;    

    bool operator==(const Livre& autre) const;

    friend ostream& operator<<(ostream& os, const Livre& livre);
};

#endif