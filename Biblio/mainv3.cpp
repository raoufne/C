// ============================================================================
// mainv3.cpp - VERSION 3 : Interface console + Stockage fichiers
// ============================================================================
// Comme V2 mais avec sauvegarde/chargement automatique dans data/
// ============================================================================

#include <iostream>
#include <fstream>
#include <limits>
#include <sys/stat.h>
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
#include <io.h>

using namespace std;

// Variables globales V3
Bibliotheque* biblioActuelleV3 = nullptr;
ListeChainee<Bibliotheque*> toutesBibliothequesV3;

// Chemin du dossier data
const string DATA_DIR = "data/";

// ============================================================================
// FONCTIONS UTILITAIRES
// ============================================================================
void viderBuffer3() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int saisirEntier3(const string& message) {
    int valeur;
    cout << message;
    while (!(cin >> valeur)) {
        cout << "Erreur! Entrez un nombre: ";
        viderBuffer3();
    }
    viderBuffer3();
    return valeur;
}

string saisirChaine3(const string& message) {
    string valeur;
    cout << message;
    getline(cin, valeur);
    return valeur;
}

void pause3() {
    cout << "\nAppuyez sur Entree pour continuer...";
    cin.get();
}

// ============================================================================
// FONCTIONS DE SAUVEGARDE
// ============================================================================

// Créer le dossier data s'il n'existe pas
void creerDossierData() {
    mkdir(DATA_DIR.c_str());
}

// Sauvegarder toutes les bibliothèques
void sauvegarderBibliotheques() {
    creerDossierData();
    ofstream fichier(DATA_DIR + "bibliotheques.txt");
    
    if (!fichier.is_open()) {
        cout << "[ERREUR] Impossible de sauvegarder les bibliotheques" << endl;
        return;
    }
    
    Noeud<Bibliotheque*>* courant = toutesBibliothequesV3.getTete();
    while (courant != nullptr) {
        Bibliotheque* b = courant->donnee;
        // Format: nom;adresse;code
        fichier << b->getNom() << ";" << b->getAdresse() << ";" << b->getCode() << endl;
        courant = courant->suivant;
    }
    fichier.close();
}

// Sauvegarder tous les livres d'une bibliothèque
void sauvegarderLivres(Bibliotheque* biblio) {
    creerDossierData();
    ofstream fichier(DATA_DIR + "livres_" + biblio->getCode() + ".txt");
    
    if (!fichier.is_open()) return;
    
    Noeud<Livre*>* courant = biblio->getLivres().getTete();
    while (courant != nullptr) {
        Livre* l = courant->donnee;
        // Format: type;code;auteur;titre;editeur;isbn;public;etat;attribut
        fichier << l->getType() << ";"
                << l->getCode() << ";"
                << l->getAuteur() << ";"
                << l->getTitre() << ";"
                << l->getEditeur() << ";"
                << l->getIsbn() << ";"
                << l->getPublicCible() << ";"
                << l->getEtat() << ";";
        
        // Attribut spécifique selon le type
        if (l->getType() == "Roman") {
            fichier << ((Roman*)l)->getGenreRoman();
        } else if (l->getType() == "BandeDessinee") {
            fichier << ((BandeDessinee*)l)->getDessinateur();
        } else if (l->getType() == "Poesie") {
            fichier << ((Poesie*)l)->getTypePoesie();
        } else if (l->getType() == "Theatre") {
            fichier << ((Theatre*)l)->getSiecle();
        } else if (l->getType() == "Album") {
            fichier << ((Album*)l)->getTypeIllustration();
        }
        fichier << endl;
        courant = courant->suivant;
    }
    fichier.close();
}

// Sauvegarder tous les adhérents d'une bibliothèque
void sauvegarderAdherents(Bibliotheque* biblio) {
    creerDossierData();
    ofstream fichier(DATA_DIR + "adherents_" + biblio->getCode() + ".txt");
    
    if (!fichier.is_open()) return;
    
    Noeud<Adherent*>* courant = biblio->getAdherents().getTete();
    while (courant != nullptr) {
        Adherent* a = courant->donnee;
        // Format: numero;nom;prenom;adresse;maxEmprunts
        fichier << a->getNumeroAdherent() << ";"
                << a->getNom() << ";"
                << a->getPrenom() << ";"
                << a->getAdresse() << ";"
                << a->getNombreMaxEmprunts() << endl;
        courant = courant->suivant;
    }
    fichier.close();
}

// Sauvegarder TOUT
void sauvegarderTout() {
    sauvegarderBibliotheques();
    
    Noeud<Bibliotheque*>* courant = toutesBibliothequesV3.getTete();
    while (courant != nullptr) {
        sauvegarderLivres(courant->donnee);
        sauvegarderAdherents(courant->donnee);
        courant = courant->suivant;
    }
    
    cout << ">> Donnees sauvegardees dans " << DATA_DIR << endl;
}

// ============================================================================
// FONCTIONS DE CHARGEMENT
// ============================================================================

// Parser une ligne CSV (séparateur ;)
void parserLigne(const string& ligne, string parties[], int maxParties) {
    int index = 0;
    string temp = "";
    
    for (size_t i = 0; i < ligne.length() && index < maxParties; i++) {
        if (ligne[i] == ';') {
            parties[index++] = temp;
            temp = "";
        } else {
            temp += ligne[i];
        }
    }
    if (index < maxParties) {
        parties[index] = temp;
    }
}

// Charger les livres d'une bibliothèque
void chargerLivres(Bibliotheque* biblio) {
    ifstream fichier(DATA_DIR + "livres_" + biblio->getCode() + ".txt");
    if (!fichier.is_open()) return;
    
    string ligne;
    while (getline(fichier, ligne)) {
        if (ligne.empty()) continue;
        
        string p[9];
        parserLigne(ligne, p, 9);
        
        string type = p[0];
        string code = p[1];
        string auteur = p[2];
        string titre = p[3];
        string editeur = p[4];
        string isbn = p[5];
        Public pub = (Public)stoi(p[6]);
        Etat etat = (Etat)stoi(p[7]);
        string attr = p[8];
        
        Livre* livre = nullptr;
        
        if (type == "Roman") {
            livre = new Roman(code, auteur, titre, editeur, isbn, pub, (GenreRoman)stoi(attr));
        } else if (type == "BandeDessinee") {
            livre = new BandeDessinee(code, auteur, titre, editeur, isbn, pub, attr);
        } else if (type == "Poesie") {
            livre = new Poesie(code, auteur, titre, editeur, isbn, pub, (TypePoesie)stoi(attr));
        } else if (type == "Theatre") {
            livre = new Theatre(code, auteur, titre, editeur, isbn, pub, stoi(attr));
        } else if (type == "Album") {
            livre = new Album(code, auteur, titre, editeur, isbn, pub, (TypeIllustration)stoi(attr));
        }
        
        if (livre) {
            livre->setEtat(etat);
            biblio->getLivres().ajouter(livre);
        }
    }
    fichier.close();
}

// Charger les adhérents d'une bibliothèque
void chargerAdherents(Bibliotheque* biblio) {
    ifstream fichier(DATA_DIR + "adherents_" + biblio->getCode() + ".txt");
    if (!fichier.is_open()) return;
    
    string ligne;
    while (getline(fichier, ligne)) {
        if (ligne.empty()) continue;
        
        string p[5];
        parserLigne(ligne, p, 5);
        
        // On ne peut pas restaurer le numéro exact, on recrée
        Adherent* adh = new Adherent(p[1], p[2], p[3], biblio, stoi(p[4]));
        biblio->getAdherents().ajouter(adh);
    }
    fichier.close();
}

// Charger toutes les bibliothèques
void chargerTout() {
    ifstream fichier(DATA_DIR + "bibliotheques.txt");
    if (!fichier.is_open()) {
        cout << ">> Aucune donnee sauvegardee trouvee." << endl;
        return;
    }
    
    string ligne;
    while (getline(fichier, ligne)) {
        if (ligne.empty()) continue;
        
        string p[3];
        parserLigne(ligne, p, 3);
        
        Bibliotheque* biblio = new Bibliotheque(p[0], p[1], p[2]);
        chargerLivres(biblio);
        chargerAdherents(biblio);
        toutesBibliothequesV3.ajouter(biblio);
    }
    fichier.close();
    
    if (toutesBibliothequesV3.getTaille() > 0) {
        biblioActuelleV3 = toutesBibliothequesV3[0];
        cout << ">> " << toutesBibliothequesV3.getTaille() << " bibliotheque(s) chargee(s) depuis " << DATA_DIR << endl;
    }
}

// ============================================================================
// MENU BIBLIOTHEQUES V3
// ============================================================================
void menuBibliothequesV3() {
    int choix;
    do {
        cout << "\n======== GESTION BIBLIOTHEQUES ========" << endl;
        cout << "1. Creer une bibliotheque" << endl;
        cout << "2. Selectionner une bibliotheque" << endl;
        cout << "3. Afficher bibliotheque actuelle" << endl;
        cout << "4. Lister toutes les bibliotheques" << endl;
        cout << "0. Retour" << endl;
        
        choix = saisirEntier3("Choix: ");
        
        switch (choix) {
            case 1: {
                string nom = saisirChaine3("Nom: ");
                string adresse = saisirChaine3("Adresse: ");
                string code = saisirChaine3("Code (ex: BIB001): ");
                
                Bibliotheque* nouvelle = new Bibliotheque(nom, adresse, code);
                toutesBibliothequesV3.ajouter(nouvelle);
                biblioActuelleV3 = nouvelle;
                sauvegarderTout();  // SAUVEGARDE AUTO
                cout << ">> Bibliotheque creee et sauvegardee!" << endl;
                break;
            }
            case 2: {
                if (toutesBibliothequesV3.getTaille() == 0) {
                    cout << "Aucune bibliotheque!" << endl;
                    break;
                }
                cout << "\nBibliotheques disponibles:" << endl;
                for (int i = 0; i < toutesBibliothequesV3.getTaille(); i++) {
                    cout << i+1 << ". " << toutesBibliothequesV3[i]->getNom() 
                         << " [" << toutesBibliothequesV3[i]->getCode() << "]" << endl;
                }
                int num = saisirEntier3("Numero: ");
                if (num >= 1 && num <= toutesBibliothequesV3.getTaille()) {
                    biblioActuelleV3 = toutesBibliothequesV3[num-1];
                    cout << ">> Bibliotheque selectionnee!" << endl;
                }
                break;
            }
            case 3:
                if (biblioActuelleV3) biblioActuelleV3->afficher();
                else cout << "Aucune bibliotheque selectionnee!" << endl;
                break;
            case 4:
                cout << "\n=== TOUTES LES BIBLIOTHEQUES ===" << endl;
                for (int i = 0; i < toutesBibliothequesV3.getTaille(); i++) {
                    cout << endl;
                    toutesBibliothequesV3[i]->afficher();
                }
                break;
        }
        if (choix != 0) pause3();
    } while (choix != 0);
}

// ============================================================================
// MENU LIVRES V3
// ============================================================================
void menuLivresV3() {
    if (!biblioActuelleV3) {
        cout << "Selectionnez d'abord une bibliotheque!" << endl;
        pause3();
        return;
    }
    
    int choix;
    do {
        cout << "\n======== GESTION LIVRES ========" << endl;
        cout << "[Biblio: " << biblioActuelleV3->getNom() << "]" << endl;
        cout << "1. Afficher tous les livres" << endl;
        cout << "2. Afficher par categorie" << endl;
        cout << "3. Afficher livres disponibles" << endl;
        cout << "4. Ajouter un livre" << endl;
        cout << "5. Supprimer un livre" << endl;
        cout << "6. Rechercher un livre" << endl;
        cout << "0. Retour" << endl;
        
        choix = saisirEntier3("Choix: ");
        
        switch (choix) {
            case 1:
                biblioActuelleV3->afficherTousLesLivres();
                break;
            case 2: {
                cout << "Categories: Roman, BandeDessinee, Poesie, Theatre, Album" << endl;
                string cat = saisirChaine3("Categorie: ");
                biblioActuelleV3->afficherLivresParCategorie(cat);
                break;
            }
            case 3:
                biblioActuelleV3->afficherLivresDisponibles();
                break;
            case 4: {
                cout << "\nType: 1=Roman 2=BD 3=Poesie 4=Theatre 5=Album" << endl;
                int type = saisirEntier3("Type: ");
                
                string code = saisirChaine3("Code: ");
                string auteur = saisirChaine3("Auteur: ");
                string titre = saisirChaine3("Titre: ");
                string editeur = saisirChaine3("Editeur: ");
                string isbn = saisirChaine3("ISBN: ");
                
                cout << "Public: 0=Adulte 1=Ados 2=Jeunesse 3=ToutPublic" << endl;
                int pub = saisirEntier3("Public: ");
                
                Livre* livre = nullptr;
                switch (type) {
                    case 1: {
                        cout << "\nGenres: 0=Litterature, 1=Noir, 2=Policier, 11=Historique, 16=Aventures, 25=Autre" << endl;
                        int genre = saisirEntier3("Genre: ");
                        livre = new Roman(code, auteur, titre, editeur, isbn, (Public)pub, (GenreRoman)genre);
                        break;
                    }
                    case 2: {
                        string dessinateur = saisirChaine3("Dessinateur: ");
                        livre = new BandeDessinee(code, auteur, titre, editeur, isbn, (Public)pub, dessinateur);
                        break;
                    }
                    case 3: {
                        cout << "Type poesie: 0=Vers 1=Prose 2=Les deux" << endl;
                        int tp = saisirEntier3("Type: ");
                        livre = new Poesie(code, auteur, titre, editeur, isbn, (Public)pub, (TypePoesie)tp);
                        break;
                    }
                    case 4: {
                        int siecle = saisirEntier3("Siecle (17, 18, 19...): ");
                        livre = new Theatre(code, auteur, titre, editeur, isbn, (Public)pub, siecle);
                        break;
                    }
                    case 5: {
                        cout << "Illustrations: 0=Photos 1=Dessins 2=Les deux" << endl;
                        int ti = saisirEntier3("Type: ");
                        livre = new Album(code, auteur, titre, editeur, isbn, (Public)pub, (TypeIllustration)ti);
                        break;
                    }
                }
                if (livre) {
                    biblioActuelleV3->acheterLivre(livre);
                    sauvegarderLivres(biblioActuelleV3);  // SAUVEGARDE AUTO
                }
                break;
            }
            case 5: {
                string code = saisirChaine3("Code du livre a supprimer: ");
                try {
                    biblioActuelleV3->supprimerLivre(code);
                    sauvegarderLivres(biblioActuelleV3);  // SAUVEGARDE AUTO
                } catch (BibliothequeException& e) {
                    cout << "[ERREUR] " << e.what() << endl;
                }
                break;
            }
            case 6: {
                string code = saisirChaine3("Code du livre: ");
                Livre* livre = biblioActuelleV3->rechercherLivreParCode(code);
                if (livre) livre->afficher();
                else cout << "Livre non trouve!" << endl;
                break;
            }
        }
        if (choix != 0) pause3();
    } while (choix != 0);
}

// ============================================================================
// MENU ADHERENTS V3
// ============================================================================
void menuAdherentsV3() {
    if (!biblioActuelleV3) {
        cout << "Selectionnez d'abord une bibliotheque!" << endl;
        pause3();
        return;
    }
    
    int choix;
    do {
        cout << "\n======== GESTION ADHERENTS ========" << endl;
        cout << "[Biblio: " << biblioActuelleV3->getNom() << "]" << endl;
        cout << "1. Afficher tous les adherents" << endl;
        cout << "2. Inscrire un adherent" << endl;
        cout << "3. Rechercher un adherent" << endl;
        cout << "4. Voir emprunts d'un adherent" << endl;
        cout << "5. Desinscrire un adherent" << endl;
        cout << "0. Retour" << endl;
        
        choix = saisirEntier3("Choix: ");
        
        switch (choix) {
            case 1:
                biblioActuelleV3->afficherTousLesAdherents();
                break;
            case 2: {
                string nom = saisirChaine3("Nom: ");
                string prenom = saisirChaine3("Prenom: ");
                string adresse = saisirChaine3("Adresse: ");
                int maxEmp = saisirEntier3("Max emprunts: ");
                
                Adherent* adh = new Adherent(nom, prenom, adresse, biblioActuelleV3, maxEmp);
                biblioActuelleV3->inscrireAdherent(adh);
                sauvegarderAdherents(biblioActuelleV3);  // SAUVEGARDE AUTO
                cout << ">> Numero adherent: " << adh->getNumeroAdherent() << endl;
                break;
            }
            case 3: {
                string num = saisirChaine3("Numero adherent (ex: ADH1): ");
                Adherent* adh = biblioActuelleV3->rechercherAdherent(num);
                if (adh) adh->afficher();
                else cout << "Adherent non trouve!" << endl;
                break;
            }
            case 4: {
                string num = saisirChaine3("Numero adherent (ex: ADH1): ");
                Adherent* adh = biblioActuelleV3->rechercherAdherent(num);
                if (adh) adh->afficherLivresEmpruntes();
                else cout << "Adherent non trouve!" << endl;
                break;
            }
            case 5: {
                string num = saisirChaine3("Numero adherent a desinscrire (ex: ADH1): ");
                try {
                    biblioActuelleV3->desinscrireAdherent(num);
                    sauvegarderAdherents(biblioActuelleV3);  // SAUVEGARDE AUTO
                    cout << ">> Adherent desinscrit!" << endl;
                } catch (BibliothequeException& e) {
                    cout << "[ERREUR] " << e.what() << endl;
                }
                break;
            }
        }
        if (choix != 0) pause3();
    } while (choix != 0);
}

// ============================================================================
// MENU EMPRUNTS V3
// ============================================================================
void menuEmpruntsV3() {
    if (!biblioActuelleV3) {
        cout << "Selectionnez d'abord une bibliotheque!" << endl;
        pause3();
        return;
    }
    
    int choix;
    do {
        cout << "\n======== EMPRUNTS / RETOURS ========" << endl;
        cout << "[Biblio: " << biblioActuelleV3->getNom() << "]" << endl;
        cout << "1. Emprunter un livre" << endl;
        cout << "2. Rendre un livre" << endl;
        cout << "0. Retour" << endl;
        
        choix = saisirEntier3("Choix: ");
        
        switch (choix) {
            case 1: {
                string numAdh = saisirChaine3("Numero adherent (ex: ADH1): ");
                Adherent* adh = biblioActuelleV3->rechercherAdherent(numAdh);
                if (!adh) {
                    cout << "Adherent non trouve!" << endl;
                    break;
                }
                
                string codeLivre = saisirChaine3("Code du livre: ");
                try {
                    adh->emprunterLivre(codeLivre);
                    sauvegarderLivres(biblioActuelleV3);  // SAUVEGARDE AUTO
                } catch (BibliothequeException& e) {
                    cout << "[ERREUR] " << e.what() << endl;
                }
                break;
            }
            case 2: {
                string numAdh = saisirChaine3("Numero adherent (ex: ADH1): ");
                Adherent* adh = biblioActuelleV3->rechercherAdherent(numAdh);
                if (!adh) {
                    cout << "Adherent non trouve!" << endl;
                    break;
                }
                
                adh->afficherLivresEmpruntes();
                string codeLivre = saisirChaine3("Code du livre a rendre: ");
                Livre* livre = biblioActuelleV3->rechercherLivreParCode(codeLivre);
                try {
                    adh->rendreLivre(livre);
                    sauvegarderLivres(biblioActuelleV3);  // SAUVEGARDE AUTO
                } catch (BibliothequeException& e) {
                    cout << "[ERREUR] " << e.what() << endl;
                }
                break;
            }
        }
        if (choix != 0) pause3();
    } while (choix != 0);
}

// ============================================================================
// MENU ECHANGES V3
// ============================================================================
void menuEchangesV3() {
    if (toutesBibliothequesV3.getTaille() < 2) {
        cout << "Il faut au moins 2 bibliotheques!" << endl;
        pause3();
        return;
    }
    
    int choix;
    do {
        cout << "\n======== ECHANGES INTER-BIBLIOTHEQUES ========" << endl;
        cout << "1. Demander un livre a une autre bibliotheque" << endl;
        cout << "2. Rendre les livres pretes" << endl;
        cout << "0. Retour" << endl;
        
        choix = saisirEntier3("Choix: ");
        
        switch (choix) {
            case 1: {
                cout << "\nBibliotheques:" << endl;
                for (int i = 0; i < toutesBibliothequesV3.getTaille(); i++) {
                    cout << i+1 << ". " << toutesBibliothequesV3[i]->getNom() << endl;
                }
                
                int numDemandeur = saisirEntier3("Bibliotheque qui demande: ");
                int numPreteur = saisirEntier3("Bibliotheque qui prete: ");
                
                if (numDemandeur < 1 || numDemandeur > toutesBibliothequesV3.getTaille() ||
                    numPreteur < 1 || numPreteur > toutesBibliothequesV3.getTaille()) {
                    cout << "Numeros invalides!" << endl;
                    break;
                }
                
                Bibliotheque* demandeur = toutesBibliothequesV3[numDemandeur-1];
                Bibliotheque* preteur = toutesBibliothequesV3[numPreteur-1];
                
                string isbn = saisirChaine3("ISBN du livre demande: ");
                demandeur->demanderLivre(preteur, isbn);
                sauvegarderTout();  // SAUVEGARDE AUTO
                break;
            }
            case 2: {
                cout << "\nBibliotheques:" << endl;
                for (int i = 0; i < toutesBibliothequesV3.getTaille(); i++) {
                    cout << i+1 << ". " << toutesBibliothequesV3[i]->getNom() << endl;
                }
                
                int numEmprunteur = saisirEntier3("Bibliotheque qui rend: ");
                int numProprietaire = saisirEntier3("Bibliotheque proprietaire: ");
                
                if (numEmprunteur < 1 || numEmprunteur > toutesBibliothequesV3.getTaille() ||
                    numProprietaire < 1 || numProprietaire > toutesBibliothequesV3.getTaille()) {
                    cout << "Numeros invalides!" << endl;
                    break;
                }
                
                Bibliotheque* emprunteur = toutesBibliothequesV3[numEmprunteur-1];
                Bibliotheque* proprietaire = toutesBibliothequesV3[numProprietaire-1];
                
                emprunteur->rendreLivresPretes(proprietaire);
                sauvegarderTout();  // SAUVEGARDE AUTO
                break;
            }
        }
        if (choix != 0) pause3();
    } while (choix != 0);
}

// ============================================================================
// FONCTION PRINCIPALE V3
// ============================================================================
void executerV3() {
    // CHARGEMENT AUTOMATIQUE AU DEMARRAGE
    cout << "\n>> Chargement des donnees..." << endl;
    chargerTout();
    
    int choix;
    do {
        cout << "\n========================================================" << endl;
        cout << "       VERSION 3 : INTERFACE + FICHIERS" << endl;
        cout << "========================================================" << endl;
        cout << "[Donnees stockees dans: " << DATA_DIR << "]" << endl;
        
        if (biblioActuelleV3) {
            cout << "[Bibliotheque actuelle: " << biblioActuelleV3->getNom() << "]" << endl;
        } else {
            cout << "[Aucune bibliotheque selectionnee]" << endl;
        }
        
        cout << "\n1. Gestion des bibliotheques" << endl;
        cout << "2. Gestion des livres" << endl;
        cout << "3. Gestion des adherents" << endl;
        cout << "4. Emprunts / Retours" << endl;
        cout << "5. Echanges inter-bibliotheques" << endl;
        cout << "6. Sauvegarder manuellement" << endl;
        cout << "0. Retour au menu principal" << endl;
        
        choix = saisirEntier3("\nChoix: ");
        
        switch (choix) {
            case 1: menuBibliothequesV3(); break;
            case 2: menuLivresV3(); break;
            case 3: menuAdherentsV3(); break;
            case 4: menuEmpruntsV3(); break;
            case 5: menuEchangesV3(); break;
            case 6: sauvegarderTout(); pause3(); break;
        }
    } while (choix != 0);
    
    // SAUVEGARDE AUTOMATIQUE A LA SORTIE
    cout << "\n>> Sauvegarde automatique..." << endl;
    sauvegarderTout();
}