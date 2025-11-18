#ifndef ENSEIGNANTVACATAIRE_H
#define ENSEIGNANTVACATAIRE_H

#include "../Personnel/Personnel.h"

class EnseignantVacataire : public Personnel {
private:
    string casier;
    int nbreHeures;
    float taux;

public:
    EnseignantVacataire(string nom="", string prenom="", float salaire=0,
                        string casier="", int nbreHeures=0, float taux=0);

    float calculSalaire() const override;
    void affiche() const override;
};

#endif
