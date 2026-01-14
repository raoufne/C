// ============================================================================
// main.cpp - MENU PRINCIPAL
// ============================================================================
// Permet de choisir entre les 3 versions du programme
// ============================================================================

#include <iostream>
#include <limits>
using namespace std;

// Déclarations des fonctions des autres fichiers
void executerV1();  // mainv1.cpp
void executerV2();  // mainv2.cpp
void executerV3();  // mainv3.cpp

// ============================================================================
// FONCTIONS UTILITAIRES
// ============================================================================
void viderBufferMain() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int saisirChoix() {
    int valeur;
    cout << "Votre choix: ";
    while (!(cin >> valeur)) {
        cout << "Erreur! Entrez un nombre: ";
        viderBufferMain();
    }
    viderBufferMain();
    return valeur;
}

// ============================================================================
// PROGRAMME PRINCIPAL
// ============================================================================
int main() {
    int choix;
    
    do {
        cout << "\n" << endl;
        cout << "============================================================" << endl;
        cout << "       SYSTEME DE GESTION DE BIBLIOTHEQUES" << endl;
        cout << "       Projet C++ - ECM S7 - 2025-2026" << endl;
        cout << "============================================================" << endl;
        cout << "\n       MENU PRINCIPAL\n" << endl;
        cout << "  1. VERSION 1 - Tests automatiques (sans interface)" << endl;
        cout << "  2. VERSION 2 - Interface console (interaction admin)" << endl;
        cout << "  3. VERSION 3 - Stockage dans fichiers" << endl;
        cout << "  0. Quitter" << endl;
        cout << "\n============================================================" << endl;
        
        choix = saisirChoix();
        
        switch (choix) {
            case 1:
                executerV1();
                break;
            case 2:
                executerV2();
                break;
            case 3:
                executerV3();
                break;
            case 0:
                cout << "\nAu revoir!" << endl;
                break;
            default:
                cout << "\nChoix invalide!" << endl;
        }
        
    } while (choix != 0);
    
    return 0;
}
