// ============================================================================
// mainv1.cpp - VERSION 1 : Tests automatiques (sans interface)
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

void afficherSection(const string& titre) {
    cout << "\n########################################################" << endl;
    cout << "  " << titre << endl;
    cout << "########################################################" << endl;
}

// ============================================================================
// FONCTION PRINCIPALE V1
// ============================================================================
void executerV1() {
    
    cout << "\n========================================================" << endl;
    cout << "       VERSION 1 : PROGRAMMATION SANS INTERFACE" << endl;
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

    // ========================================================================
    // TEST 2 : Création et achat de livres (HERITAGE)
    // ========================================================================
    afficherSection("TEST 2 : Achat de livres (HERITAGE)");
    
    // Création de livres de différents types (HERITAGE)
    Roman* roman1 = new Roman("ROM001", "Victor Hugo", "Les Miserables", 
                               "Gallimard", "978-2-07-040850-4", ADULTE, ROMAN_HISTORIQUE);
    Roman* roman2 = new Roman("ROM002", "Agatha Christie", "Mort sur le Nil", 
                               "Le Masque", "978-2-7024-1234-5", ADULTE, ROMAN_POLICIER);
    BandeDessinee* bd1 = new BandeDessinee("BD001", "Goscinny", "Asterix le Gaulois", 
                                           "Dargaud", "978-2-01-210034-5", TOUT_PUBLIC, "Uderzo");
    Poesie* poesie1 = new Poesie("POE001", "Baudelaire", "Les Fleurs du Mal", 
                                  "Poulet-Malassis", "978-2-07-032057-8", ADULTE, VERS);
    Theatre* theatre1 = new Theatre("THE001", "Moliere", "Le Malade Imaginaire", 
                                     "Barbin", "978-2-07-040512-1", TOUT_PUBLIC, 17);
    Album* album1 = new Album("ALB001", "Eric Carle", "La Chenille qui fait des trous", 
                               "Mijade", "978-2-87142-000-0", JEUNESSE, DESSINS);
    
    // Ajout à biblio1
    biblio1.acheterLivre(roman1);
    biblio1.acheterLivre(roman2);
    biblio1.acheterLivre(bd1);
    biblio1.acheterLivre(poesie1);
    biblio1.acheterLivre(theatre1);
    biblio1.acheterLivre(album1);
    
    // Ajout à biblio2
    Roman* roman3 = new Roman("ROM003", "Zola", "Germinal", 
                               "Charpentier", "978-2-07-036789-0", ADULTE, ROMAN_MOEURS);
    Roman* roman4 = new Roman("ROM004", "Camus", "L'Etranger", 
                               "Gallimard", "978-2-07-036024-2", ADULTE, LITTERATURE);

    biblio2.acheterLivre(roman3);
    biblio2.acheterLivre(roman4);
    
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
    
    cout << "[POLYMORPHISME] getType() retourne le vrai type de chaque livre\n" << endl;
    
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
    
    cout << "\n[FONCTION AMIE] Utilisation de cout << adherent:" << endl;
    cout << "  " << *adh1 << endl;
    cout << "  " << *adh2 << endl;
    
    cout << "\n[MEMBRE STATIQUE] Nombre total d'adherents: " 
         << Adherent::getCompteurAdherents() << endl;

    // ========================================================================
    // TEST 6 : Emprunt de livres PAR CODE
    // ========================================================================
    afficherSection("TEST 6 : Emprunt de livres PAR CODE");
    
    cout << "Marie emprunte des livres en donnant le CODE...\n" << endl;
    
    try {
        adh1->emprunterLivre("ROM001");
        adh1->emprunterLivre("BD001");
        
        cout << endl;
        adh1->afficherLivresEmpruntes();
        
    } catch (BibliothequeException& e) {
        cout << "[EXCEPTION] " << e.what() << endl;
    }

    // ========================================================================
    // TEST 7 : Test EXCEPTION - Limite d'emprunt
    // ========================================================================
    afficherSection("TEST 7 : Test EXCEPTION - Limite d'emprunt");
    
    cout << "Marie (limite = 3) emprunte un 3eme puis tente un 4eme...\n" << endl;
    
    try {
        adh1->emprunterLivre("POE001");  // 3eme : OK
        cout << ">> 3eme emprunt OK (limite atteinte)\n" << endl;
        
        adh1->emprunterLivre("THE001");  // 4eme : ERREUR !
        
    } catch (LimiteEmpruntException& e) {
        cout << "[EXCEPTION ATTRAPEE] " << e.what() << endl;
    }

    // ========================================================================
    // TEST 8 : Test EXCEPTION - Livre non disponible
    // ========================================================================
    afficherSection("TEST 8 : Test EXCEPTION - Livre non disponible");
    
    cout << "Pierre essaie d'emprunter ROM001 (deja emprunte par Marie)...\n" << endl;
    
    try {
        adh2->emprunterLivre("ROM001");
        
    } catch (LivreNonDisponibleException& e) {
        cout << "[EXCEPTION ATTRAPEE] " << e.what() << endl;
    }

    // ========================================================================
    // TEST 9 : Retour de livre 
    // ========================================================================
    afficherSection("TEST 9 : Retour de livre");
    
    cout << "Marie rend le livre ROM001...\n" << endl;
    
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
    
    // CAS 1 : Prêt réussi
    cout << "=== CAS 1 : Pret reussi ===" << endl;
    cout << "Biblio1 demande 'Germinal' (ROM003) a Biblio2...\n" << endl;
    
    bool succes1 = biblio1.demanderLivre(&biblio2, "978-2-07-036789-0");
    if (succes1) {
        cout << ">> Echange reussi !" << endl;
    }
    
    // CAS 2 : Prêt impossible (livre déjà prêté)
    cout << "\n=== CAS 2 : Pret impossible (livre deja prete) ===" << endl;
    cout << "Biblio1 demande encore 'Germinal' a Biblio2...\n" << endl;
    
    bool succes2 = biblio1.demanderLivre(&biblio2, "978-2-07-036789-0");
    if (!succes2) {
        cout << ">> Echange refuse (livre non disponible)" << endl;
    }

    // ========================================================================
    // TEST 12 : Suppression d'un livre
    // ========================================================================
    afficherSection("TEST 12 : Suppression d'un livre");
    
    // CAS 1 : Suppression OK
    cout << "=== CAS 1 : Suppression reussie ===" << endl;
    cout << "Suppression de ROM002 (Mort sur le Nil)...\n" << endl;
    
    try {
        biblio1.supprimerLivre("ROM002");
    } catch (BibliothequeException& e) {
        cout << "[EXCEPTION] " << e.what() << endl;
    }
    
    // ========================================================================
    // TEST 13 : Rendre livres prêtés (entre bibliothèques)
    // ========================================================================
    afficherSection("TEST 13 : Rendre livres pretes entre bibliotheques");
    
    cout << "Biblio1 rend les livres pretes a Biblio2...\n" << endl;
    
    // Afficher état avant
    cout << "Etat de 'Germinal' avant retour: ";
    Livre* germinal = biblio1.rechercherLivreParCode("ROM003");
    if (germinal) {
        cout << germinal->etatToString() << endl;
    }
    
    // Rendre le livre
    biblio1.rendreLivresPretes(&biblio2);
    
    // Afficher état après
    cout << "\nEtat de 'Germinal' apres retour: ";
    if (germinal) {
        cout << germinal->etatToString() << endl;
    }

    // ========================================================================
    // FIN
    // ========================================================================
    afficherSection("FIN VERSION 1");
    
    cout << "\nAppuyez sur Entree pour revenir au menu..." << endl;
    cin.get();
}
