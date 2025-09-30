#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    int dimension;         
    double* coords;        
    static int compteur;  

public:
    Vector();

    Vector(int dim);

    Vector(int dim, const double values[]);

    Vector(const Vector& v);

    ~Vector();

    double getCoordinate(int index) const;

    void setCoordinate(int index, double value);

    void afficher() const;

    double norme() const;

    bool egal(const Vector& v) const;

    double produitScalaire(const Vector& v) const;

    Vector operator*(double k) const;

    Vector operator+(const Vector& v) const;

    static int getCompteur();
};

#endif
