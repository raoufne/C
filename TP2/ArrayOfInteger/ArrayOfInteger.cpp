#include "ArrayOfInteger.h"

int ArrayOfInteger::compteur = 0;

ArrayOfInteger::ArrayOfInteger() : size(0), capacity(10) {
    data = new int[capacity];
    for (int i = 0; i < capacity; i++) data[i] = 0;
    compteur++;
}

ArrayOfInteger::ArrayOfInteger(int cap) : size(0), capacity(cap) {
    data = new int[capacity];
    for (int i = 0; i < capacity; i++) data[i] = 0;
    compteur++;
}

ArrayOfInteger::ArrayOfInteger(int n, const int values[]) {
    capacity = (n > 10 ? n : 10);
    data = new int[capacity];
    size = 0;
    for (int i = 0; i < n; i++) {
        ajouter(values[i]); 
    }
    compteur++;
}

ArrayOfInteger::ArrayOfInteger(const ArrayOfInteger& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
    compteur++;
}

ArrayOfInteger::~ArrayOfInteger() {
    delete[] data;
    compteur--;
}

bool ArrayOfInteger::containsInternal(int x) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == x) return true;
    }
    return false;
}

void ArrayOfInteger::afficher() const {
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " }" << endl;
}

bool ArrayOfInteger::contains(int x) const {
    return containsInternal(x);
}

void ArrayOfInteger::ajouter(int x) {
    if (containsInternal(x)) return; 

    if (size >= capacity) {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

    data[size++] = x;
}

void ArrayOfInteger::retirer(int x) {
    for (int i = 0; i < size; i++) {
        if (data[i] == x) {
            for (int j = i; j < size - 1; j++) {
                data[j] = data[j + 1];
            }
            size--;
            return;
        }
    }
}

bool ArrayOfInteger::egal(const ArrayOfInteger& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; i++) {
        if (!other.containsInternal(data[i])) return false;
    }
    return true;
}

int ArrayOfInteger::getCompteur() {
    return compteur;
}
