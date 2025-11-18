#ifndef ELEVE_H
#define ELEVE_H

#include "../Personne/Personne.h"

class Eleve : public Personne {
protected:
    string promotion;
    string groupeTD;
    float GPA;

public:
    Eleve(string nom="", string prenom="", string promotion="", float GPA=-1, string groupeTD="");

    void setPromotion(string p);
    void setGroupeTD(string g);
    void setGPA(float g);

    string getPromotion() const;
    string getGroupeTD() const;
    float getGPA() const;

    void affiche() const override;
};

#endif
