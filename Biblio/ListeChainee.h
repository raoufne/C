// ============================================================================
// ListeChainee.h - Liste chaînée générique (TEMPLATE)
// ============================================================================
// CONCEPT : TEMPLATE
// Un template permet de créer une classe qui marche avec N'IMPORTE QUEL type
// ListeChainee<int> = liste d'entiers
// ListeChainee<Livre*> = liste de pointeurs vers des livres
// ListeChainee<Adherent*> = liste de pointeurs vers des adhérents
// ============================================================================
// CONCEPT : LISTE CHAINEE
// Chaque élément (Noeud) contient :
//   - une donnée
//   - un pointeur vers l'élément suivant
// C'est comme une chaîne où chaque maillon pointe vers le suivant
// ============================================================================
// IMPORTANT : Pour un template, TOUT le code est dans le .h (pas de .cpp)
// ============================================================================

#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H

#include <iostream>
using namespace std;

// ============================================================================
// STRUCTURE NOEUD - Un maillon de la chaîne
// ============================================================================
// template<typename T> signifie : T est un type générique (int, Livre*, etc.)

template<typename T>
struct Noeud {
    T donnee;           // La donnée stockée
    Noeud<T>* suivant;  // Pointeur vers le noeud suivant
    
    // Constructeur du noeud
    Noeud(T d) : donnee(d), suivant(nullptr) {}
};

// ============================================================================
// CLASSE LISTECHAINEE
// ============================================================================

template<typename T>
class ListeChainee {

private:
    Noeud<T>* tete;  // Pointeur vers le premier élément
    int taille;      // Nombre d'éléments

public:
    // ========================================================================
    // CONSTRUCTEUR
    // ========================================================================
    ListeChainee() {
        tete = nullptr;  // Liste vide au départ
        taille = 0;
    }

    // ========================================================================
    // DESTRUCTEUR
    // ========================================================================
    ~ListeChainee() {
        vider();
    }

    // ========================================================================
    // ajouter() - Ajoute un élément à la fin de la liste
    // ========================================================================
    void ajouter(T element) {
        Noeud<T>* nouveauNoeud = new Noeud<T>(element);
        
        if (tete == nullptr) {
            // Liste vide : le nouveau noeud devient la tête
            tete = nouveauNoeud;
        } else {
            // Sinon on parcourt jusqu'à la fin
            Noeud<T>* courant = tete;
            while (courant->suivant != nullptr) {
                courant = courant->suivant;
            }
            courant->suivant = nouveauNoeud;
        }
        taille++;
    }

    // ========================================================================
    // supprimer() - Supprime un élément de la liste
    // ========================================================================
    bool supprimer(T element) {
        if (tete == nullptr) {
            return false;  // Liste vide
        }
        
        // Cas spécial : l'élément est en tête
        if (tete->donnee == element) {
            Noeud<T>* temp = tete;
            tete = tete->suivant;
            delete temp;
            taille--;
            return true;
        }
        
        // Sinon on cherche l'élément
        Noeud<T>* courant = tete;
        while (courant->suivant != nullptr && !(courant->suivant->donnee == element)) {
            courant = courant->suivant;
        }
        
        // Si trouvé
        if (courant->suivant != nullptr) {
            Noeud<T>* temp = courant->suivant;
            courant->suivant = courant->suivant->suivant;
            delete temp;
            taille--;
            return true;
        }
        
        return false;  // Non trouvé
    }

    // ========================================================================
    // getElement() - Récupère l'élément à l'index donné
    // ========================================================================
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

    // ========================================================================
    // getTaille() - Retourne le nombre d'éléments
    // ========================================================================
    int getTaille() const {
        return taille;
    }

    // ========================================================================
    // estVide() - Vérifie si la liste est vide
    // ========================================================================
    bool estVide() const {
        return (taille == 0);
    }

    // ========================================================================
    // vider() - Supprime tous les éléments
    // ========================================================================
    void vider() {
        while (tete != nullptr) {
            Noeud<T>* temp = tete;
            tete = tete->suivant;
            delete temp;
        }
        taille = 0;
    }

    // ========================================================================
    // getTete() - Retourne le premier noeud (pour parcourir)
    // ========================================================================
    Noeud<T>* getTete() const {
        return tete;
    }

    // ========================================================================
    // REDEFINITION OPERATEUR [] - Accès par index
    // ========================================================================
    // Permet d'écrire : liste[0], liste[1], etc.
    T operator[](int index) const {
        return getElement(index);
    }

    // ========================================================================
    // REDEFINITION OPERATEUR += - Ajouter un élément
    // ========================================================================
    // Permet d'écrire : liste += element;
    ListeChainee<T>& operator+=(T element) {
        ajouter(element);
        return *this;
    }
};

#endif // LISTECHAINEE_H