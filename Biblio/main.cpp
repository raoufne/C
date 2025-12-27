// ============================================================================
// main.cpp - Programme principal avec tests
// ============================================================================
// Ce fichier teste TOUTES les fonctionnalités du projet.
// Les objets sont créés "en dur" (pas de saisie utilisateur).
// ============================================================================

#include <iostream>
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
// Fonction utilitaire pour afficher un titre de section
// ============================================================================
void afficherSection(const string& titre) {
    cout << "\n";
    cout << "########################################################" << endl;
    cout << "  " << titre << endl;
    cout << "########################################################" << endl;
}

// ============================================================================
// PROGRAMME PRINCIPAL
// ============================================================================
int main() {
    
    cout << "========================================================" << endl;
    cout << "       SYSTEME DE GESTION DE BIBLIOTHEQUES" << endl;
    cout << "       Projet C++ - ECM S7 - 2025-2026" << endl;
    cout << "========================================================" << endl;

    // ========================================================================
    // TEST 1 : Création des bibliothèques
    // ========================================================================
    afficherSection("TEST 1 : Creation des bibliotheques");
    
    Bibliotheque biblio1("Bibliotheque Centrale", "12 rue des Livres, Paris", "BIB001");
    Bibliotheque biblio2("Mediatheque du Lac", "5 avenue du Lac, Lyon", "BIB002");
    
    biblio1.afficher();
    cout << endl;
    biblio2.afficher();
    
    // MEMBRE STATIQUE : nombre total de bibliothèques
    cout << "\n[MEMBRE STATIQUE] Nombre total de bibliotheques: " 
         << Bibliotheque::getNombreTotalBibliotheques() << endl;

    // ========================================================================
    // TEST 2 : Création et achat de livres (HERITAGE)
    // ========================================================================
    afficherSection("TEST 2 : Achat de livres (HERITAGE)");
    
    // Création de Romans
    Roman* roman1 = new Roman("ROM001", "Victor Hugo", "Les Miserables", 
                               "Gallimard", "978-2-07-040850-4", ADULTE, "Historique");
    Roman* roman2 = new Roman("ROM002", "Agatha Christie", "Mort sur le Nil", 
                               "Le Masque", "978-2-7024-1234-5", ADULTE, "Policier");
    
    // Création de BD
    BandeDessinee* bd1 = new BandeDessinee("BD001", "Goscinny", "Asterix le Gaulois", 
                                           "Dargaud", "978-2-01-210034-5", TOUT_PUBLIC, "Uderzo");
    
    // Création de Poésie
    Poesie* poesie1 = new Poesie("POE001", "Baudelaire", "Les Fleurs du Mal", 
                                  "Poulet-Malassis", "978-2-07-032057-8", ADULTE, VERS);
    
    // Création de Théâtre
    Theatre* theatre1 = new Theatre("THE001", "Moliere", "Le Malade Imaginaire", 
                                     "Barbin", "978-2-07-040512-1", TOUT_PUBLIC, 17);
    
    // Création d'Album
    Album* album1 = new Album("ALB001", "Eric Carle", "La Chenille qui fait des trous", 
                               "Mijade", "978-2-87142-000-0", JEUNESSE, DESSINS);
    
    // Ajout des livres à la bibliothèque 1
    biblio1.acheterLivre(roman1);
    biblio1.acheterLivre(roman2);
    biblio1.acheterLivre(bd1);
    biblio1.acheterLivre(poesie1);
    biblio1.acheterLivre(theatre1);
    biblio1.acheterLivre(album1);
    
    // Ajout d'un livre à la bibliothèque 2
    Roman* roman3 = new Roman("ROM003", "Zola", "Germinal", 
                               "Charpentier", "978-2-07-036789-0", ADULTE, "Naturaliste");
    biblio2.acheterLivre(roman3);
    
    // MEMBRE STATIQUE : nombre total de livres
    cout << "\n[MEMBRE STATIQUE] Nombre total de livres: " 
         << Livre::getNombreTotalLivres() << endl;

    // ========================================================================
    // TEST 3 : Affichage du catalogue (LISTE CHAINEE)
    // ========================================================================
    afficherSection("TEST 3 : Affichage du catalogue (LISTE CHAINEE)");
    
    biblio1.afficherTousLesLivres();

    // ========================================================================
    // TEST 4 : Affichage par catégorie (POLYMORPHISME)
    // ========================================================================
    afficherSection("TEST 4 : Affichage par categorie (POLYMORPHISME)");
    
    cout << "[POLYMORPHISME] getType() retourne le vrai type de chaque livre" << endl;
    
    biblio1.afficherLivresParCategorie("Roman");
    biblio1.afficherLivresParCategorie("BandeDessinee");

    // ========================================================================
    // TEST 5 : Inscription d'adhérents
    // ========================================================================
    afficherSection("TEST 5 : Inscription d'adherents");
    
    Adherent* adh1 = new Adherent("Dupont", "Marie", "10 rue de la Paix", &biblio1, 3);
    Adherent* adh2 = new Adherent("Martin", "Pierre", "25 avenue Foch", &biblio1, 2);
    
    biblio1.inscrireAdherent(adh1);
    biblio1.inscrireAdherent(adh2);
    
    // FONCTION AMIE : operator<<
    cout << "\n[FONCTION AMIE] Utilisation de cout << adherent:" << endl;
    cout << "  " << *adh1 << endl;
    cout << "  " << *adh2 << endl;
    
    // MEMBRE STATIQUE
    cout << "\n[MEMBRE STATIQUE] Nombre total d'adherents crees: " 
         << Adherent::getCompteurAdherents() << endl;

    // ========================================================================
    // TEST 6 : Emprunt de livres
    // ========================================================================
    afficherSection("TEST 6 : Emprunt de livres");
    
    cout << "Marie emprunte des livres..." << endl;
    
    // CONCEPT : TRY-CATCH pour les EXCEPTIONS
    try {
        adh1->emprunterLivre(roman1);
        adh1->emprunterLivre(bd1);
        
        cout << endl;
        adh1->afficherLivresEmpruntes();
        
    } catch (BibliothequeException& e) {
        cout << "[EXCEPTION] " << e.what() << endl;
    }

    // ========================================================================
    // TEST 7 : Test EXCEPTION - Limite d'emprunt
    // ========================================================================
    afficherSection("TEST 7 : Test EXCEPTION - Limite d'emprunt");
    
    cout << "Marie (limite = 3 livres) essaie d'emprunter 2 livres de plus..." << endl;
    
    try {
        adh1->emprunterLivre(poesie1);  // 3eme livre : OK
        adh1->emprunterLivre(theatre1); // 4eme livre : ERREUR !
        
    } catch (LimiteEmpruntException& e) {
        cout << "[EXCEPTION ATTRAPEE] " << e.what() << endl;
    }

    // ========================================================================
    // TEST 8 : Test EXCEPTION - Livre non disponible
    // ========================================================================
    afficherSection("TEST 8 : Test EXCEPTION - Livre non disponible");
    
    cout << "Pierre essaie d'emprunter un livre deja emprunte par Marie..." << endl;
    
    try {
        adh2->emprunterLivre(roman1);  // Déjà emprunté par Marie !
        
    } catch (LivreNonDisponibleException& e) {
        cout << "[EXCEPTION ATTRAPEE] " << e.what() << endl;
    }

    // ========================================================================
    // TEST 9 : Retour de livre
    // ========================================================================
    afficherSection("TEST 9 : Retour de livre");
    
    cout << "Marie rend un livre..." << endl;
    
    try {
        adh1->rendreLivre(roman1);
        cout << endl;
        adh1->afficherLivresEmpruntes();
        
    } catch (BibliothequeException& e) {
        cout << "[EXCEPTION] " << e.what() << endl;
    }

    // ========================================================================
    // TEST 10 : Affichage des livres disponibles
    // ========================================================================
    afficherSection("TEST 10 : Livres disponibles");
    
    biblio1.afficherLivresDisponibles();

    // ========================================================================
    // TEST 11 : Echange entre bibliothèques
    // ========================================================================
    afficherSection("TEST 11 : Echange entre bibliotheques");
    
    cout << "La biblio1 demande 'Germinal' a biblio2..." << endl;
    
    bool succes = biblio1.demanderLivre(&biblio2, "978-2-07-036789-0");
    
    if (succes) {
        cout << "\nEchange reussi !" << endl;
    }

    // ========================================================================
    // TEST 12 : Suppression d'un livre
    // ========================================================================
    afficherSection("TEST 12 : Suppression d'un livre (mise au pilon)");
    
    cout << "Suppression du livre ROM002..." << endl;
    
    try {
        biblio1.supprimerLivre("ROM002");
    } catch (BibliothequeException& e) {
        cout << "[EXCEPTION] " << e.what() << endl;
    }
    
    cout << "\nTentative de supprimer un livre emprunte (BD001)..." << endl;
    
    try {
        biblio1.supprimerLivre("BD001");  // Emprunté par Marie !
    } catch (LivreNonDisponibleException& e) {
        cout << "[EXCEPTION ATTRAPEE] " << e.what() << endl;
    }

    // ========================================================================
    // TEST 13 : Test de la liste chaînée (TEMPLATE)
    // ========================================================================
    afficherSection("TEST 13 : Test TEMPLATE ListeChainee");
    
    cout << "[TEMPLATE] ListeChainee fonctionne avec n'importe quel type" << endl;
    
    // Liste d'entiers
    ListeChainee<int> listeInt;
    listeInt += 10;  // OPERATEUR +=
    listeInt += 20;
    listeInt += 30;
    
    cout << "\nListe d'entiers: ";
    for (int i = 0; i < listeInt.getTaille(); i++) {
        cout << listeInt[i] << " ";  // OPERATEUR []
    }
    cout << endl;
    
    // Liste de strings
    ListeChainee<string> listeStr;
    listeStr.ajouter("Bonjour");
    listeStr.ajouter("le");
    listeStr.ajouter("monde");
    
    cout << "Liste de strings: ";
    for (int i = 0; i < listeStr.getTaille(); i++) {
        cout << listeStr[i] << " ";
    }
    cout << endl;

    // ========================================================================
    // TEST 14 : Opérateur == (REDEFINITION D'OPERATEUR)
    // ========================================================================
    afficherSection("TEST 14 : Test OPERATEUR ==");
    
    cout << "[REDEFINITION OPERATEUR] Comparaison avec ==" << endl;
    
    if (biblio1 == biblio2) {
        cout << "biblio1 et biblio2 sont identiques" << endl;
    } else {
        cout << "biblio1 et biblio2 sont differentes" << endl;
    }
    
    if (*adh1 == *adh1) {
        cout << "adh1 est egal a lui-meme (OK)" << endl;
    }

    // ========================================================================
    // RESUME DES CONCEPTS C++ UTILISES
    // ========================================================================
    afficherSection("RESUME DES CONCEPTS C++ UTILISES");
    
    cout << "1. HERITAGE.............. Roman, BD, Poesie, Theatre, Album heritent de Livre" << endl;
    cout << "2. CLASSES VIRTUELLES.... Livre est abstraite (afficher() = 0)" << endl;
    cout << "3. POLYMORPHISME......... getType() et afficher() selon le vrai type" << endl;
    cout << "4. EXCEPTIONS............ try-catch avec LimiteEmpruntException, etc." << endl;
    cout << "5. LISTE CHAINEE......... ListeChainee<T> avec Noeud<T>" << endl;
    cout << "6. TEMPLATE.............. ListeChainee<int>, ListeChainee<Livre*>, etc." << endl;
    cout << "7. OPERATEURS............ ==, [], +=, <<" << endl;
    cout << "8. FONCTIONS AMIES....... friend operator<<" << endl;
    cout << "9. MEMBRES STATIQUES..... nombreTotalLivres, compteurAdherents" << endl;

    // ========================================================================
    // FIN
    // ========================================================================
    afficherSection("FIN DU PROGRAMME");
    
    cout << "Statistiques finales:" << endl;
    cout << "  - Bibliotheques: " << Bibliotheque::getNombreTotalBibliotheques() << endl;
    cout << "  - Livres: " << Livre::getNombreTotalLivres() << endl;
    cout << "  - Adherents: " << Adherent::getCompteurAdherents() << endl;
    
    cout << "\nProgramme termine avec succes !" << endl;
    
    // Nettoyage mémoire
    delete adh1;
    delete adh2;
    
    return 0;
}