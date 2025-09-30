#include "ArrayOfInteger.h"

int ArrayOfInteger::compteur = 0;

// Constructeur par défaut
ArrayOfInteger::ArrayOfInteger() : size(0), capacity(10) {
    data = new int[capacity];
    for (int i = 0; i < capacity; i++) data[i] = 0;
    compteur++;
}

// Constructeur avec capacité
ArrayOfInteger::ArrayOfInteger(int cap) : size(0), capacity(cap) {
    data = new int[capacity];
    for (int i = 0; i < capacity; i++) data[i] = 0;
    compteur++;
}

// Constructeur avec tableau d'éléments
ArrayOfInteger::ArrayOfInteger(int n, const int values[]) {
    capacity = (n > 10 ? n : 10);
    data = new int[capacity];
    size = 0;
    for (int i = 0; i < n; i++) {
        ajouter(values[i]); // utilise la méthode qui gère doublons
    }
    compteur++;
}

// Constructeur de recopie
ArrayOfInteger::ArrayOfInteger(const ArrayOfInteger& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
    compteur++;
}

// Destructeur
ArrayOfInteger::~ArrayOfInteger() {
    delete[] data;
    compteur--;
}

// Fonction interne
bool ArrayOfInteger::containsInternal(int x) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == x) return true;
    }
    return false;
}

// Affichage
void ArrayOfInteger::afficher() const {
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " }" << endl;
}

// Test appartenance
bool ArrayOfInteger::contains(int x) const {
    return containsInternal(x);
}

// Ajouter un élément
void ArrayOfInteger::ajouter(int x) {
    if (containsInternal(x)) return; // déjà présent

    if (size >= capacity) {
        // doubler la capacité
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

    data[size++] = x;
}

// Retirer un élément
void ArrayOfInteger::retirer(int x) {
    for (int i = 0; i < size; i++) {
        if (data[i] == x) {
            // décale le reste
            for (int j = i; j < size - 1; j++) {
                data[j] = data[j + 1];
            }
            size--;
            return;
        }
    }
}

// Vérifier égalité
bool ArrayOfInteger::egal(const ArrayOfInteger& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; i++) {
        if (!other.containsInternal(data[i])) return false;
    }
    return true;
}

// Compteur
int ArrayOfInteger::getCompteur() {
    return compteur;
}
