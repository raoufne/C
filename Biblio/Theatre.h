#ifndef THEATRE_H
#define THEATRE_H

#include "Livre.h"

class Theatre : public Livre {

private:
    int siecle; 

public:
    Theatre();
    
    Theatre(string code, string auteur, string titre, string editeur,
            string isbn, Public publicCible, int siecle);

    ~Theatre();

    void afficher() const override;
    string getType() const override;

    int getSiecle() const;

    string siecleToString() const;
};

#endif