#ifndef BANDEDESSINEE_H
#define BANDEDESSINEE_H

#include "Livre.h"
class BandeDessinee : public Livre {

private:
    string dessinateur;

public:
    BandeDessinee();
    
    BandeDessinee(string code, string auteur, string titre, string editeur,
                  string isbn, Public publicCible, string dessinateur);

    ~BandeDessinee();

    void afficher() const override;
    string getType() const override;

    string getDessinateur() const;
};

#endif