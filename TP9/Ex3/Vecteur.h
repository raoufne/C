#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
using namespace std;

template <class T>
class Vecteur {
    T* data;
    int n;

public:
    Vecteur(int n);
    ~Vecteur();

    T& operator[](int i);
    int size() const;
};

template <class T>
Vecteur<T>::Vecteur(int n) : n(n) {
    data = new T[n];
}

template <class T>
Vecteur<T>::~Vecteur() {
    delete[] data;
}

template <class T>
T& Vecteur<T>::operator[](int i) {
    if (i < 0 || i >= n) {
        cout << "Erreur : indice hors limites !" << endl;
        exit(1);
    }
    return data[i];
}

template <class T>
int Vecteur<T>::size() const {
    return n;
}

#endif
