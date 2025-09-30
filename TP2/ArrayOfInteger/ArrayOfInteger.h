#ifndef ARRAYOFINTEGER_H
#define ARRAYOFINTEGER_H

#include <iostream>
using namespace std;

class ArrayOfInteger {
private:
    int* data;          
    int size;           
    int capacity;       // taille du tableau alloué
    static int compteur; // compteur d'instances

    // Fonction utilitaire pour vérifier doublon
    bool containsInternal(int x) const;

public:
    // Constructeur par défaut
    ArrayOfInteger();

    // Constructeur avec capacité initiale
    ArrayOfInteger(int cap);

    // Constructeur avec tableau d'éléments
    ArrayOfInteger(int n, const int values[]);

    // Constructeur de recopie
    ArrayOfInteger(const ArrayOfInteger& other);

    // Destructeur
    ~ArrayOfInteger();

    // Méthode affichage
    void afficher() const;

    // Test appartenance
    bool contains(int x) const;

    // Ajouter un élément
    void ajouter(int x);

    // Retirer un élément
    void retirer(int x);

    // Vérifier égalité
    bool egal(const ArrayOfInteger& other) const;

    // Getter pour taille
    int getSize() const { return size; }

    // Compteur instances
    static int getCompteur();
};

#endif
