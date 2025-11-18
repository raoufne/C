#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "../Personne/Personne.h"

class Personnel : public Personne {
protected:
    float salaire;

public:
    Personnel(string nom="", string prenom="", float salaire=0);

    void setSalaire(float s);
    float getSalaire() const;

    virtual float calculSalaire() const = 0;
    void affiche() const override;
};

#endif
