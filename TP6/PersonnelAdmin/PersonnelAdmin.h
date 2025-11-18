#ifndef PERSONNELADMIN_H
#define PERSONNELADMIN_H

#include "../Personnel/Personnel.h"

class PersonnelAdmin : public Personnel {
private:
    int heuresSup;
    float taux;

public:
    PersonnelAdmin(string nom="", string prenom="", float salaire=0,
                   int heuresSup=0, float taux=0);

    float calculSalaire() const override;
    void affiche() const override;
};

#endif
