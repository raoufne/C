#include <iostream>
#include <limits>
#include "Livre.h"
#include "Roman.h"
#include "BandeDessinee.h"
#include "Poesie.h"
#include "Theatre.h"
#include "Album.h"
#include "Bibliotheque.h"
#include "Adherent.h"
#include "Exceptions.h"
#include "ListeChainee.h"

using namespace std;

Bibliotheque* biblioActuelle = nullptr;
ListeChainee<Bibliotheque*> toutesBibliotheques;

void viderBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int saisirEntier(const string& message) {
    int valeur;
    cout << message;
    while (!(cin >> valeur)) {
        cout << "Erreur! Entrez un nombre: ";
        viderBuffer();
    }
    viderBuffer();
    return valeur;
}

string saisirChaine(const string& message) {
    string valeur;
    cout << message;
    getline(cin, valeur);
    return valeur;
}

void pause() {
    cout << "\nAppuyez sur Entree pour continuer...";
    cin.get();
}

void menuBibliotheques() {
    int choix;
    do {
        cout << "\n======== GESTION BIBLIOTHEQUES ========" << endl;
        cout << "1. Creer une bibliotheque" << endl;
        cout << "2. Selectionner une bibliotheque" << endl;
        cout << "3. Afficher bibliotheque actuelle" << endl;
        cout << "4. Lister toutes les bibliotheques" << endl;
        cout << "0. Retour" << endl;
        
        choix = saisirEntier("Choix: ");
        
        switch (choix) {
            case 1: {
                string nom = saisirChaine("Nom: ");
                string adresse = saisirChaine("Adresse: ");
                string code = saisirChaine("Code (ex: BIB001): ");
                
                Bibliotheque* nouvelle = new Bibliotheque(nom, adresse, code);
                toutesBibliotheques.ajouter(nouvelle);
                biblioActuelle = nouvelle;
                cout << ">> Bibliotheque creee et selectionnee!" << endl;
                break;
            }
            case 2: {
                if (toutesBibliotheques.getTaille() == 0) {
                    cout << "Aucune bibliotheque!" << endl;
                    break;
                }
                cout << "\nBibliotheques disponibles:" << endl;
                for (int i = 0; i < toutesBibliotheques.getTaille(); i++) {
                    cout << i+1 << ". " << toutesBibliotheques[i]->getNom() 
                         << " [" << toutesBibliotheques[i]->getCode() << "]" << endl;
                }
                int num = saisirEntier("Numero: ");
                if (num >= 1 && num <= toutesBibliotheques.getTaille()) {
                    biblioActuelle = toutesBibliotheques[num-1];
                    cout << ">> Bibliotheque selectionnee!" << endl;
                }
                break;
            }
            case 3:
                if (biblioActuelle) biblioActuelle->afficher();
                else cout << "Aucune bibliotheque selectionnee!" << endl;
                break;
            case 4:
                cout << "\n=== TOUTES LES BIBLIOTHEQUES ===" << endl;
                for (int i = 0; i < toutesBibliotheques.getTaille(); i++) {
                    cout << endl;
                    toutesBibliotheques[i]->afficher();
                }
                break;
        }
        if (choix != 0) pause();
    } while (choix != 0);
}

void menuLivres() {
    if (!biblioActuelle) {
        cout << "Selectionnez d'abord une bibliotheque!" << endl;
        pause();
        return;
    }
    
    int choix;
    do {
        cout << "\n======== GESTION LIVRES ========" << endl;
        cout << "[Biblio: " << biblioActuelle->getNom() << "]" << endl;
        cout << "1. Afficher tous les livres" << endl;
        cout << "2. Afficher par categorie" << endl;
        cout << "3. Afficher livres disponibles" << endl;
        cout << "4. Ajouter un livre" << endl;
        cout << "5. Supprimer un livre" << endl;
        cout << "6. Rechercher un livre" << endl;
        cout << "0. Retour" << endl;
        
        choix = saisirEntier("Choix: ");
        
        switch (choix) {
            case 1:
                biblioActuelle->afficherTousLesLivres();
                break;
            case 2: {
                cout << "Categories: Roman, BandeDessinee, Poesie, Theatre, Album" << endl;
                string cat = saisirChaine("Categorie: ");
                biblioActuelle->afficherLivresParCategorie(cat);
                break;
            }
            case 3:
                biblioActuelle->afficherLivresDisponibles();
                break;
            case 4: {
                cout << "\nType: 1=Roman 2=BD 3=Poesie 4=Theatre 5=Album" << endl;
                int type = saisirEntier("Type: ");
                
                string code = saisirChaine("Code: ");
                string auteur = saisirChaine("Auteur: ");
                string titre = saisirChaine("Titre: ");
                string editeur = saisirChaine("Editeur: ");
                string isbn = saisirChaine("ISBN: ");
                
                cout << "Public: 0=Adulte 1=Ados 2=Jeunesse 3=ToutPublic" << endl;
                int pub = saisirEntier("Public: ");
                
                Livre* livre = nullptr;
                switch (type) {
                    case 1: {
                        cout << "\nGenres disponibles:" << endl;
                        cout << "0=Litterature, 1=Noir, 2=Policier, 3=Animalier, 4=Amour" << endl;
                        cout << "5=Moeurs, 6=Gothique, 7=Courtois, 8=Epistolaire, 9=Feuilleton" << endl;
                        cout << "10=Graphique, 11=Historique, 12=Photo, 13=Picaresque, 14=Memoires" << endl;
                        cout << "15=Populaire, 16=Aventures, 17=Anticipation, 18=Espionnage" << endl;
                        cout << "19=Apprentissage, 20=Chevalerie, 21=Autobiographique" << endl;
                        cout << "22=Nouveau roman, 23=Conte, 24=Nouvelle, 25=Autre" << endl;
                        int genre = saisirEntier("Genre: ");
                        livre = new Roman(code, auteur, titre, editeur, isbn, (Public)pub, (GenreRoman)genre);
                        break;
                    }
                    case 2: {
                        string dessinateur = saisirChaine("Dessinateur: ");
                        livre = new BandeDessinee(code, auteur, titre, editeur, isbn, (Public)pub, dessinateur);
                        break;
                    }
                    case 3: {
                        cout << "Type poesie: 0=Vers 1=Prose 2=Les deux" << endl;
                        int tp = saisirEntier("Type: ");
                        livre = new Poesie(code, auteur, titre, editeur, isbn, (Public)pub, (TypePoesie)tp);
                        break;
                    }
                    case 4: {
                        int siecle = saisirEntier("Siecle (17, 18, 19...): ");
                        livre = new Theatre(code, auteur, titre, editeur, isbn, (Public)pub, siecle);
                        break;
                    }
                    case 5: {
                        cout << "Illustrations: 0=Photos 1=Dessins 2=Les deux" << endl;
                        int ti = saisirEntier("Type: ");
                        livre = new Album(code, auteur, titre, editeur, isbn, (Public)pub, (TypeIllustration)ti);
                        break;
                    }
                }
                if (livre) {
                    biblioActuelle->acheterLivre(livre);
                }
                break;
            }
            case 5: {
                string code = saisirChaine("Code du livre a supprimer: ");
                try {
                    biblioActuelle->supprimerLivre(code);
                } catch (BibliothequeException& e) {
                    cout << "[ERREUR] " << e.what() << endl;
                }
                break;
            }
            case 6: {
                string code = saisirChaine("Code du livre: ");
                Livre* livre = biblioActuelle->rechercherLivreParCode(code);
                if (livre) livre->afficher();
                else cout << "Livre non trouve!" << endl;
                break;
            }
        }
        if (choix != 0) pause();
    } while (choix != 0);
}

void menuAdherents() {
    if (!biblioActuelle) {
        cout << "Selectionnez d'abord une bibliotheque!" << endl;
        pause();
        return;
    }
    
    int choix;
    do {
        cout << "\n======== GESTION ADHERENTS ========" << endl;
        cout << "[Biblio: " << biblioActuelle->getNom() << "]" << endl;
        cout << "1. Afficher tous les adherents" << endl;
        cout << "2. Inscrire un adherent" << endl;
        cout << "3. Rechercher un adherent" << endl;
        cout << "4. Voir emprunts d'un adherent" << endl;
        cout << "5. Desinscrire un adherent" << endl;
        cout << "0. Retour" << endl;
        
        choix = saisirEntier("Choix: ");
        
        switch (choix) {
            case 1:
                biblioActuelle->afficherTousLesAdherents();
                break;
            case 2: {
                string nom = saisirChaine("Nom: ");
                string prenom = saisirChaine("Prenom: ");
                string adresse = saisirChaine("Adresse: ");
                int maxEmp = saisirEntier("Max emprunts: ");
                
                Adherent* adh = new Adherent(nom, prenom, adresse, biblioActuelle, maxEmp);
                biblioActuelle->inscrireAdherent(adh);
                cout << ">> Numero adherent: " << adh->getNumeroAdherent() << endl;
                break;
            }
            case 3: {
                string num = "ADH" + saisirChaine("Numero adherent: ");

                Adherent* adh = biblioActuelle->rechercherAdherent(num);
                if (adh) adh->afficher();
                else cout << "Adherent non trouve!" << endl;
                break;
            }
            case 4: {
                string num = "ADH" + saisirChaine("Numero adherent: ");
                Adherent* adh = biblioActuelle->rechercherAdherent(num);
                if (adh) adh->afficherLivresEmpruntes();
                else cout << "Adherent non trouve!" << endl;
                break;
            }
            case 5: {
                string num = "ADH" + saisirChaine("Numero adherent a desinscrire: ");
                try {
                    biblioActuelle->desinscrireAdherent(num);
                } catch (BibliothequeException& e) {
                    cout << "[ERREUR] " << e.what() << endl;
                }
                break;
            }
        }
        if (choix != 0) pause();
    } while (choix != 0);
}

void menuEmprunts() {
    if (!biblioActuelle) {
        cout << "Selectionnez d'abord une bibliotheque!" << endl;
        pause();
        return;
    }
    
    int choix;
    do {
        cout << "\n======== EMPRUNTS / RETOURS ========" << endl;
        cout << "[Biblio: " << biblioActuelle->getNom() << "]" << endl;
        cout << "1. Emprunter un livre" << endl;
        cout << "2. Rendre un livre" << endl;
        cout << "0. Retour" << endl;
        
        choix = saisirEntier("Choix: ");
        
        switch (choix) {
            case 1: {
                string numAdh = "ADH" + saisirChaine("Numero adherent: ");
                Adherent* adh = biblioActuelle->rechercherAdherent(numAdh);
                if (!adh) {
                    cout << "Adherent non trouve!" << endl;
                    break;
                }
                
                string codeLivre = saisirChaine("Code du livre: ");
                try {
                    adh->emprunterLivre(codeLivre);
                } catch (BibliothequeException& e) {
                    cout << "[ERREUR] " << e.what() << endl;
                }
                break;
            }
            case 2: {
                string numAdh = "ADH" + saisirChaine("Numero adherent: ");
                Adherent* adh = biblioActuelle->rechercherAdherent(numAdh);
                if (!adh) {
                    cout << "Adherent non trouve!" << endl;
                    break;
                }
                
                adh->afficherLivresEmpruntes();
                string codeLivre = saisirChaine("Code du livre a rendre: ");
                Livre* livre = biblioActuelle->rechercherLivreParCode(codeLivre);
                
                try {
                    adh->rendreLivre(livre);
                } catch (BibliothequeException& e) {
                    cout << "[ERREUR] " << e.what() << endl;
                }
                break;
            }
        }
        if (choix != 0) pause();
    } while (choix != 0);
}

void menuEchanges() {
    if (toutesBibliotheques.getTaille() < 2) {
        cout << "Il faut au moins 2 bibliotheques!" << endl;
        pause();
        return;
    }
    
    int choix;
    do {
        cout << "\n======== ECHANGES INTER-BIBLIOTHEQUES ========" << endl;
        cout << "1. Demander un livre a une autre bibliotheque" << endl;
        cout << "2. Rendre les livres pretes" << endl;
        cout << "0. Retour" << endl;
        
        choix = saisirEntier("Choix: ");
        
        switch (choix) {
            case 1: {
                cout << "\nBibliotheques:" << endl;
                for (int i = 0; i < toutesBibliotheques.getTaille(); i++) {
                    cout << i+1 << ". " << toutesBibliotheques[i]->getNom() << endl;
                }
                
                int numDemandeur = saisirEntier("Bibliotheque qui demande: ");
                int numPreteur = saisirEntier("Bibliotheque qui prete: ");
                
                if (numDemandeur < 1 || numDemandeur > toutesBibliotheques.getTaille() ||
                    numPreteur < 1 || numPreteur > toutesBibliotheques.getTaille()) {
                    cout << "Numeros invalides!" << endl;
                    break;
                }
                
                Bibliotheque* demandeur = toutesBibliotheques[numDemandeur-1];
                Bibliotheque* preteur = toutesBibliotheques[numPreteur-1];
                
                string isbn = saisirChaine("ISBN du livre demande: ");
                demandeur->demanderLivre(preteur, isbn);
                break;
            }
            case 2: {
                cout << "\nBibliotheques:" << endl;
                for (int i = 0; i < toutesBibliotheques.getTaille(); i++) {
                    cout << i+1 << ". " << toutesBibliotheques[i]->getNom() << endl;
                }
                
                int numEmprunteur = saisirEntier("Bibliotheque qui rend: ");
                int numProprietaire = saisirEntier("Bibliotheque proprietaire: ");
                
                if (numEmprunteur < 1 || numEmprunteur > toutesBibliotheques.getTaille() ||
                    numProprietaire < 1 || numProprietaire > toutesBibliotheques.getTaille()) {
                    cout << "Numeros invalides!" << endl;
                    break;
                }
                
                Bibliotheque* emprunteur = toutesBibliotheques[numEmprunteur-1];
                Bibliotheque* proprietaire = toutesBibliotheques[numProprietaire-1];
                
                emprunteur->rendreLivresPretes(proprietaire);
                break;
            }
        }
        if (choix != 0) pause();
    } while (choix != 0);
}

void executerV2() {
    int choix;
    do {
        cout << "\n========================================================" << endl;
        cout << "       VERSION 2 : INTERFACE CONSOLE" << endl;
        cout << "========================================================" << endl;
        
        if (biblioActuelle) {
            cout << "[Bibliotheque actuelle: " << biblioActuelle->getNom() << "]" << endl;
        } else {
            cout << "[Aucune bibliotheque selectionnee]" << endl;
        }
        
        cout << "\n1. Gestion des bibliotheques" << endl;
        cout << "2. Gestion des livres" << endl;
        cout << "3. Gestion des adherents" << endl;
        cout << "4. Emprunts / Retours" << endl;
        cout << "5. Echanges inter-bibliotheques" << endl;
        cout << "0. Retour au menu principal" << endl;
        
        choix = saisirEntier("\nChoix: ");
        
        switch (choix) {
            case 1: menuBibliotheques(); break;
            case 2: menuLivres(); break;
            case 3: menuAdherents(); break;
            case 4: menuEmprunts(); break;
            case 5: menuEchanges(); break;
        }
    } while (choix != 0);
}
