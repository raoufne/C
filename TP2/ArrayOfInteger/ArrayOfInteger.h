#ifndef ARRAYOFINTEGER_H
#define ARRAYOFINTEGER_H

#include <iostream>
using namespace std;

class ArrayOfInteger {
private:
    int* data;          
    int size;           
    int capacity;       
    static int compteur; 

    bool containsInternal(int x) const;

public:
    ArrayOfInteger();

    ArrayOfInteger(int cap);

    ArrayOfInteger(int n, const int values[]);

    ArrayOfInteger(const ArrayOfInteger& other);

    ~ArrayOfInteger();

    void afficher() const;

    bool contains(int x) const;

    void ajouter(int x);

    void retirer(int x);

    bool egal(const ArrayOfInteger& other) const;

    int getSize() const { return size; }

    static int getCompteur();
};

#endif
