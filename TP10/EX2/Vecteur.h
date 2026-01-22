#ifndef VECTEUR_H
#define VECTEUR_H

class Vecteur
{
    int nombreElements;
    int * elements;

public:
    Vecteur(int n);
    ~Vecteur();
    int & operator[](int i);
};

#endif
