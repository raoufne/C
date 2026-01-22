#include "Vecteur.h"
#include "VecteurLimite.h"
#include "VecteurCreation.h"
#include <iostream>
using namespace std;

Vecteur::Vecteur(int n)
{
    if (n <= 0)
    {
        throw VecteurCreation(n);   // exception création
    }

    nombreElements = n;
    elements = new int[n];

    for (int i = 0; i < n; i++)
        elements[i] = 0;
}

Vecteur::~Vecteur()
{
    delete[] elements;
}

int & Vecteur::operator[](int i)
{
    if (i < 0 || i >= nombreElements)
    {
        throw VecteurLimite(i); 
    }

    return elements[i];
}
