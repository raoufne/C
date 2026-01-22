#ifndef POESIE_H
#define POESIE_H

#include "Livre.h"

enum TypePoesie {
    VERS,
    PROSE,
    VERS_ET_PROSE
};

class Poesie : public Livre {

private:
    TypePoesie typePoesie;

public:
    Poesie();
    
    Poesie(string code, string auteur, string titre, string editeur,
           string isbn, Public publicCible, TypePoesie typePoesie);

    ~Poesie();

    void afficher() const override;
    string getType() const override;

    TypePoesie getTypePoesie() const;

    string typePoesieToString() const;
};

#endif