#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H

#include <iostream>
using namespace std;

template<typename T>
struct Noeud {
    T donnee;           
    Noeud<T>* suivant;  
    
    Noeud(T d) : donnee(d), suivant(nullptr) {}
};

template<typename T>
class ListeChainee {

private:
    Noeud<T>* tete;  
    int taille;      

public:
    ListeChainee() {
        tete = nullptr;
        taille = 0;
    }

    ~ListeChainee() {
        vider();
    }
    
    void ajouter(T element) {
        Noeud<T>* nouveauNoeud = new Noeud<T>(element);
        
        if (tete == nullptr) {
            tete = nouveauNoeud;
        } else {
            Noeud<T>* courant = tete;
            while (courant->suivant != nullptr) {
                courant = courant->suivant;
            }
            courant->suivant = nouveauNoeud;
        }
        taille++;
    }
    bool supprimer(T element) {
        if (tete == nullptr) {
            return false; 
        }
        
        if (tete->donnee == element) {
            Noeud<T>* temp = tete;
            tete = tete->suivant;
            delete temp;
            taille--;
            return true;
        }
        
        Noeud<T>* courant = tete;
        while (courant->suivant != nullptr && !(courant->suivant->donnee == element)) {
            courant = courant->suivant;
        }
        
        if (courant->suivant != nullptr) {
            Noeud<T>* temp = courant->suivant;
            courant->suivant = courant->suivant->suivant;
            delete temp;
            taille--;
            return true;
        }
        
        return false;  
    }

    T getElement(int index) const {
        if (index < 0 || index >= taille) {
            throw out_of_range("Index hors limites");
        }
        
        Noeud<T>* courant = tete;
        for (int i = 0; i < index; i++) {
            courant = courant->suivant;
        }
        return courant->donnee;
    }

    int getTaille() const {
        return taille;
    }

    bool estVide() const {
        return (taille == 0);
    }

    void vider() {
        while (tete != nullptr) {
            Noeud<T>* temp = tete;
            tete = tete->suivant;
            delete temp;
        }
        taille = 0;
    }

    Noeud<T>* getTete() const {
        return tete;
    }

    T operator[](int index) const {
        return getElement(index);
    }

    ListeChainee<T>& operator+=(T element) {
        ajouter(element);
        return *this;
    }
};

#endif