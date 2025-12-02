#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
using namespace std;

template <class T>
class Vecteur {
    T* data;
    int n;

public:
    Vecteur(int n) : n(n) {
        data = new T[n];
    }

    ~Vecteur() {
        delete[] data;
    }

    T& operator[](int i) {
        if (i < 0 || i >= n) {
            cout << "Erreur : indice hors limites !" << endl;
            exit(1);
        }
        return data[i];
    }

    int size() const {
        return n;
    }
};

#endif
