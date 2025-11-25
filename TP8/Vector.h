#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
    double* tab;
    int taille;

    static int compteur;

public:
    Vector();                       
    Vector(int n);                 
    Vector(double a);               
    Vector(double a, double b);    
    Vector(double a, double b, double c);    
    Vector(double a, double b, double c, double d);

    Vector(const Vector& v);       
    ~Vector();                      

    Vector& operator=(const Vector& v);   
    Vector operator+(const Vector& v) const;
    Vector& operator+=(const Vector& v);

    double operator*(const Vector& v) const; 


    Vector operator*(double s) const;       
    friend Vector operator*(double s, const Vector& v); 

    bool operator==(const Vector& v) const;
    bool operator!=(const Vector& v) const;


    int getTaille() const;
    double get(int i) const;
    void set(int i, double val);

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    static int getCompteur();
};

#endif
