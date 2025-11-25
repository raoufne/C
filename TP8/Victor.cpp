#include "Vector.h"
#include <iostream>
using namespace std;

int Vector::compteur = 0;



Vector::Vector() : tab(nullptr), taille(0) {
    compteur++;
}

Vector::Vector(int n) : taille(n) {
    tab = new double[n];
    for(int i = 0; i < n; i++) tab[i] = 0;
    compteur++;
}

Vector::Vector(double a) : taille(1) {
    tab = new double[1];
    tab[0] = a;
    compteur++;
}

Vector::Vector(double a, double b) : taille(2) {
    tab = new double[2]{a, b};
    compteur++;
}

Vector::Vector(double a, double b, double c) : taille(3) {
    tab = new double[3]{a, b, c};
    compteur++;
}

Vector::Vector(double a, double b, double c, double d) : taille(4) {
    tab = new double[4]{a, b, c, d};
    compteur++;
}

Vector::Vector(const Vector& v) : taille(v.taille) {
    if(taille == 0) {
        tab = nullptr;
    } else {
        tab = new double[taille];
        for(int i = 0; i < taille; i++)
            tab[i] = v.tab[i];
    }
    compteur++;
}

Vector::~Vector() {
    delete[] tab;
    compteur--;
}



Vector& Vector::operator=(const Vector& v) {
    if(this != &v) {
        delete[] tab;

        taille = v.taille;
        if(taille == 0) {
            tab = nullptr;
        } else {
            tab = new double[taille];
            for(int i = 0; i < taille; i++)
                tab[i] = v.tab[i];
        }
    }
    return *this;
}



Vector Vector::operator+(const Vector& v) const {
    if(taille != v.taille) {
        throw std::runtime_error("Vecteurs de tailles differentes");
    }

    Vector res(taille);
    for(int i = 0; i < taille; i++)
        res.tab[i] = tab[i] + v.tab[i];
    return res;
}

Vector& Vector::operator+=(const Vector& v) {
    if(taille != v.taille) {
        throw std::runtime_error("Vecteurs de tailles differentes");
    }

    for(int i = 0; i < taille; i++)
        tab[i] += v.tab[i];
    return *this;
}



double Vector::operator*(const Vector& v) const {
    if(taille != v.taille) {
        throw std::runtime_error("Vecteurs de tailles differentes");
    }

    double produit = 0;
    for(int i = 0; i < taille; i++)
        produit += tab[i] * v.tab[i];

    return produit;
}



Vector Vector::operator*(double s) const {
    Vector res(taille);
    for(int i = 0; i < taille; i++)
        res.tab[i] = tab[i] * s;
    return res;
}

Vector operator*(double s, const Vector& v) {
    return v * s;
}



bool Vector::operator==(const Vector& v) const {
    if(taille != v.taille) return false;

    for(int i = 0; i < taille; i++)
        if(tab[i] != v.tab[i])
            return false;
    return true;
}

bool Vector::operator!=(const Vector& v) const {
    return !(*this == v);
}



int Vector::getTaille() const {
    return taille;
}

double Vector::get(int i) const {
    return tab[i];
}

void Vector::set(int i, double val) {
    tab[i] = val;
}


ostream& operator<<(ostream& os, const Vector& v) {
    os << "[ ";
    for(int i = 0; i < v.taille; i++) {
        os << v.tab[i];
        if(i < v.taille - 1) os << ", ";
    }
    os << " ]";
    return os;
}


int Vector::getCompteur() {
    return compteur;
}
