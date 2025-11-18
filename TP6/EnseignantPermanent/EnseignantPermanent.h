#ifndef ENSEIGNANTPERMANENT_H
#define ENSEIGNANTPERMANENT_H

#include "../Personnel/Personnel.h"

class EnseignantPermanent : public Personnel {
private:
    string bureau;
    int grade;
    float primeMensuelle;

public:
    EnseignantPermanent(string nom="", string prenom="", float salaire=0,
                        string bureau="", int grade=0, float primeMensuelle=0);

    float calculSalaire() const override;
    void affiche() const override;
};

#endif
