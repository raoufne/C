#ifndef HEURE_H
#define HEURE_H

#include <iostream>
using namespace std;

class Heure {
private:
    int h, min;
    bool checkHeure(int h, int min);

public:
    Heure();                   
    Heure(int h, int min);     

    int getH() const;
    int getMin() const;

    void setH(int h);
    void setMin(int min);

    void saisir();
    void affiche() const;

    bool estEgal(const Heure& h) const;
};

#endif
