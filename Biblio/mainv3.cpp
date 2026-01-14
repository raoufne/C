// ============================================================================
// mainv3.cpp - VERSION 3 : Stockage dans des fichiers
// ============================================================================

#include <iostream>
#include <fstream>
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
// SAUVEGARDER LIVRES
// ============================================================================
void sauvegarderLivres(Bibliotheque* biblio, const string& nomFichier) {
    ofstream fichier(nomFichier);
    
    if (!fichier.is_open()) {
        cout << "Erreur: impossible d'ouvrir " << nomFichier << endl;
        return;
    }
    
    Noeud<Livre*>* courant = biblio->getLivres().getTete();
    
    while (courant != nullptr) {
        Livre* livre = courant->donnee;
        
        // Format: TYPE;code;auteur;titre;editeur;isbn;public;etat;attribut
        fichier << livre->getType() << ";";
        fichier << livre->getCode() << ";";
        fichier << livre->getAuteur() << ";";
        fichier << livre->getTitre() << ";";
        fichier << livre->getEditeur() << ";";
        fichier << livre->getIsbn() << ";";
        fichier << livre->getPublicCible() << ";";
        fichier << livre->getEtat() << ";";
        
        // Attribut spécifique
        if (livre->getType() == "Roman") {
            fichier << ((Roman*)livre)->getGenreRoman();
        } else if (livre->getType() == "BandeDessinee") {
            fichier << ((BandeDessinee*)livre)->getDessinateur();
        } else if (livre->getType() == "Poesie") {
            fichier << ((Poesie*)livre)->getTypePoesie();
        } else if (livre->getType() == "Theatre") {
            fichier << ((Theatre*)livre)->getSiecle();
        } else if (livre->getType() == "Album") {
            fichier << ((Album*)livre)->getTypeIllustration();
        }
        
        fichier << endl;
        courant = courant->suivant;
    }
    
    fichier.close();
    cout << ">> Livres sauvegardes dans " << nomFichier << endl;
}

// ============================================================================
// CHARGER LIVRES
// ============================================================================
void chargerLivres(Bibliotheque* biblio, const string& nomFichier) {
    ifstream fichier(nomFichier);
    
    if (!fichier.is_open()) {
        cout << "Fichier " << nomFichier << " non trouve." << endl;
        return;
    }
    
    string ligne;
    while (getline(fichier, ligne)) {
        if (ligne.empty()) continue;
        
        // Parser la ligne
        string parties[9];
        int index = 0;
        string temp = "";
        
        for (char c : ligne) {
            if (c == ';') {
                parties[index++] = temp;
                temp = "";
            } else {
                temp += c;
            }
        }
        parties[index] = temp;
        
        string type = parties[0];
        string code = parties[1];
        string auteur = parties[2];
        string titre = parties[3];
        string editeur = parties[4];
        string isbn = parties[5];
        Public pub = (Public)stoi(parties[6]);
        Etat etat = (Etat)stoi(parties[7]);
        string attrSpec = parties[8];
        
        Livre* livre = nullptr;
        
        if (type == "Roman") {
            livre = new Roman(code, auteur, titre, editeur, isbn, pub, (GenreRoman)stoi(attrSpec));
        } else if (type == "BandeDessinee") {
            livre = new BandeDessinee(code, auteur, titre, editeur, isbn, pub, attrSpec);
        } else if (type == "Poesie") {
            livre = new Poesie(code, auteur, titre, editeur, isbn, pub, (TypePoesie)stoi(attrSpec));
        } else if (type == "Theatre") {
            livre = new Theatre(code, auteur, titre, editeur, isbn, pub, stoi(attrSpec));
        } else if (type == "Album") {
            livre = new Album(code, auteur, titre, editeur, isbn, pub, (TypeIllustration)stoi(attrSpec));
        }
        
        if (livre != nullptr) {
            livre->setEtat(etat);
            biblio->getLivres().ajouter(livre);
        }
    }
    
    fichier.close();
    cout << ">> Livres charges depuis " << nomFichier << endl;
}

// ============================================================================
// SAUVEGARDER ADHERENTS
// ============================================================================
void sauvegarderAdherents(Bibliotheque* biblio, const string& nomFichier) {
    ofstream fichier(nomFichier);
    
    if (!fichier.is_open()) {
        cout << "Erreur: impossible d'ouvrir " << nomFichier << endl;
        return;
    }
    
    Noeud<Adherent*>* courant = biblio->getAdherents().getTete();
    
    while (courant != nullptr) {
        Adherent* adh = courant->donnee;
        
        // Format: nom;prenom;adresse;maxEmprunts
        fichier << adh->getNom() << ";";
        fichier << adh->getPrenom() << ";";
        fichier << adh->getAdresse() << ";";
        fichier << adh->getNombreMaxEmprunts() << endl;
        
        courant = courant->suivant;
    }
    
    fichier.close();
    cout << ">> Adherents sauvegardes dans " << nomFichier << endl;
}

// ============================================================================
// CHARGER ADHERENTS
// ============================================================================
void chargerAdherents(Bibliotheque* biblio, const string& nomFichier) {
    ifstream fichier(nomFichier);
    
    if (!fichier.is_open()) {
        cout << "Fichier " << nomFichier << " non trouve." << endl;
        return;
    }
    
    string ligne;
    while (getline(fichier, ligne)) {
        if (ligne.empty()) continue;
        
        string parties[4];
        int index = 0;
        string temp = "";
        
        for (char c : ligne) {
            if (c == ';') {
                parties[index++] = temp;
                temp = "";
            } else {
                temp += c;
            }
        }
        parties[index] = temp;
        
        Adherent* adh = new Adherent(parties[0], parties[1], parties[2], biblio, stoi(parties[3]));
        biblio->getAdherents().ajouter(adh);
    }
    
    fichier.close();
    cout << ">> Adherents charges depuis " << nomFichier << endl;
}

// ============================================================================
// SAUVEGARDER BIBLIOTHEQUE
// ============================================================================
void sauvegarderBibliotheque(Bibliotheque* biblio, const string& nomFichier) {
    ofstream fichier(nomFichier);
    
    if (!fichier.is_open()) {
        cout << "Erreur: impossible d'ouvrir " << nomFichier << endl;
        return;
    }
    
    fichier << biblio->getNom() << ";" << biblio->getAdresse() << ";" << biblio->getCode() << endl;
    fichier.close();
    
    // Sauvegarder aussi livres et adhérents
    string code = biblio->getCode();
    sauvegarderLivres(biblio, "livres_" + code + ".txt");
    sauvegarderAdherents(biblio, "adherents_" + code + ".txt");
    
    cout << ">> Bibliotheque sauvegardee!" << endl;
}

// ============================================================================
// CHARGER BIBLIOTHEQUE
// ============================================================================
Bibliotheque* chargerBibliotheque(const string& code) {
    string nomFichier = "biblio_" + code + ".txt";
    ifstream fichier(nomFichier);
    
    if (!fichier.is_open()) {
        cout << "Fichier " << nomFichier << " non trouve." << endl;
        return nullptr;
    }
    
    string ligne;
    getline(fichier, ligne);
    fichier.close();
    
    // Parser nom;adresse;code
    string parties[3];
    int index = 0;
    string temp = "";
    for (char c : ligne) {
        if (c == ';') {
            parties[index++] = temp;
            temp = "";
        } else {
            temp += c;
        }
    }
    parties[index] = temp;
    
    Bibliotheque* biblio = new Bibliotheque(parties[0], parties[1], parties[2]);
    chargerLivres(biblio, "livres_" + code + ".txt");
    chargerAdherents(biblio, "adherents_" + code + ".txt");
    
    return biblio;
}

// ============================================================================
// CREER DONNEES DE TEST ET SAUVEGARDER
// ============================================================================
void creerEtSauvegarderDonneesTest() {
    cout << "\n=== Creation des donnees de test ===" << endl;
    
    // Créer bibliothèque 1
    Bibliotheque* biblio1 = new Bibliotheque("Bibliotheque Centrale", "12 rue des Livres, Paris", "BIB001");
    
    // Ajouter livres
    biblio1->getLivres().ajouter(new Roman("ROM001", "Victor Hugo", "Les Miserables", "Gallimard", "978-111", ADULTE, ROMAN_HISTORIQUE));
    biblio1->getLivres().ajouter(new Roman("ROM002", "Agatha Christie", "Mort sur le Nil", "Le Masque", "978-222", ADULTE, ROMAN_POLICIER));
    biblio1->getLivres().ajouter(new BandeDessinee("BD001", "Goscinny", "Asterix", "Dargaud", "978-333", TOUT_PUBLIC, "Uderzo"));
    biblio1->getLivres().ajouter(new Theatre("THE001", "Moliere", "Le Malade Imaginaire", "Barbin", "978-444", TOUT_PUBLIC, 17));
    
    // Ajouter adhérents
    biblio1->getAdherents().ajouter(new Adherent("Dupont", "Marie", "Paris", biblio1, 3));
    biblio1->getAdherents().ajouter(new Adherent("Martin", "Pierre", "Lyon", biblio1, 3));
    
    // Sauvegarder
    ofstream f1("biblio_BIB001.txt");
    f1 << biblio1->getNom() << ";" << biblio1->getAdresse() << ";" << biblio1->getCode() << endl;
    f1.close();
    sauvegarderLivres(biblio1, "livres_BIB001.txt");
    sauvegarderAdherents(biblio1, "adherents_BIB001.txt");
    
    // Créer bibliothèque 2
    Bibliotheque* biblio2 = new Bibliotheque("Mediatheque du Lac", "5 avenue du Lac, Lyon", "BIB002");
    biblio2->getLivres().ajouter(new Roman("ROM003", "Zola", "Germinal", "Charpentier", "978-555", ADULTE, ROMAN_MOEURS));
    biblio2->getLivres().ajouter(new Poesie("POE001", "Baudelaire", "Les Fleurs du Mal", "Edition", "978-666", ADULTE, VERS));
    
    ofstream f2("biblio_BIB002.txt");
    f2 << biblio2->getNom() << ";" << biblio2->getAdresse() << ";" << biblio2->getCode() << endl;
    f2.close();
    sauvegarderLivres(biblio2, "livres_BIB002.txt");
    sauvegarderAdherents(biblio2, "adherents_BIB002.txt");
    
    cout << "\n>> Donnees de test creees et sauvegardees!" << endl;
    cout << "   Fichiers crees:" << endl;
    cout << "   - biblio_BIB001.txt, livres_BIB001.txt, adherents_BIB001.txt" << endl;
    cout << "   - biblio_BIB002.txt, livres_BIB002.txt, adherents_BIB002.txt" << endl;
    
    delete biblio1;
    delete biblio2;
}

// ============================================================================
// FONCTION PRINCIPALE V3
// ============================================================================
void executerV3() {
    Bibliotheque* biblioChargee = nullptr;
    
    int choix;
    do {
        cout << "\n========================================================" << endl;
        cout << "       VERSION 3 : STOCKAGE FICHIERS" << endl;
        cout << "========================================================" << endl;
        
        if (biblioChargee) {
            cout << "[Bibliotheque chargee: " << biblioChargee->getNom() << "]" << endl;
        }
        
        cout << "\n1. Creer donnees de test (et sauvegarder)" << endl;
        cout << "2. Charger une bibliotheque depuis fichier" << endl;
        cout << "3. Afficher bibliotheque chargee" << endl;
        cout << "4. Afficher livres" << endl;
        cout << "5. Afficher adherents" << endl;
        cout << "6. Sauvegarder bibliotheque actuelle" << endl;
        cout << "0. Retour au menu principal" << endl;
        
        choix = saisirEntier3("\nChoix: ");
        
        switch (choix) {
            case 1:
                creerEtSauvegarderDonneesTest();
                break;
            case 2: {
                string code = saisirChaine3("Code de la bibliotheque (ex: BIB001): ");
                biblioChargee = chargerBibliotheque(code);
                if (biblioChargee) {
                    cout << ">> Bibliotheque chargee avec succes!" << endl;
                }
                break;
            }
            case 3:
                if (biblioChargee) biblioChargee->afficher();
                else cout << "Aucune bibliotheque chargee!" << endl;
                break;
            case 4:
                if (biblioChargee) biblioChargee->afficherTousLesLivres();
                else cout << "Aucune bibliotheque chargee!" << endl;
                break;
            case 5:
                if (biblioChargee) biblioChargee->afficherTousLesAdherents();
                else cout << "Aucune bibliotheque chargee!" << endl;
                break;
            case 6:
                if (biblioChargee) {
                    ofstream f("biblio_" + biblioChargee->getCode() + ".txt");
                    f << biblioChargee->getNom() << ";" << biblioChargee->getAdresse() << ";" << biblioChargee->getCode() << endl;
                    f.close();
                    sauvegarderLivres(biblioChargee, "livres_" + biblioChargee->getCode() + ".txt");
                    sauvegarderAdherents(biblioChargee, "adherents_" + biblioChargee->getCode() + ".txt");
                } else {
                    cout << "Aucune bibliotheque a sauvegarder!" << endl;
                }
                break;
        }
        if (choix != 0) pause3();
    } while (choix != 0);
    
    if (biblioChargee) delete biblioChargee;
}
