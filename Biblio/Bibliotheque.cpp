// ============================================================================
// Bibliotheque.cpp - Implémentation de la classe Bibliotheque
// ============================================================================

#include "Bibliotheque.h"
#include "Adherent.h"


// ============================================================================
// CONSTRUCTEUR PAR DEFAUT
// ============================================================================
Bibliotheque::Bibliotheque() {
    nom = "";
    adresse = "";
    code = "";
}

// ============================================================================
// CONSTRUCTEUR AVEC PARAMETRES
// ============================================================================
Bibliotheque::Bibliotheque(string nom, string adresse, string code) {
    this->nom = nom;
    this->adresse = adresse;
    this->code = code;
}

// ============================================================================
// DESTRUCTEUR
// ============================================================================
Bibliotheque::~Bibliotheque() {
    // Note: on ne supprime pas les livres ici pour éviter les problèmes
}

// ============================================================================
// afficherTousLesLivres() - Affiche tous les livres
// ============================================================================
void Bibliotheque::afficherTousLesLivres() const {
    cout << "\n============================================" << endl;
    cout << "  CATALOGUE: " << nom << endl;
    cout << "============================================" << endl;
    
    if (livres.getTaille() == 0) {
        cout << "  (aucun livre)" << endl;
        return;
    }
    
    // Parcours de la liste chaînée
    Noeud<Livre*>* courant = livres.getTete();
    while (courant != nullptr) {
        cout << endl;
        courant->donnee->afficher();  // POLYMORPHISME : appelle la bonne méthode
        courant = courant->suivant;
    }
    
    cout << "\nTotal: " << livres.getTaille() << " livre(s)" << endl;
}

// ============================================================================
// afficherLivresParCategorie() - Affiche les livres d'un type donné
// ============================================================================
// CONCEPT : POLYMORPHISME
// getType() retourne "Roman", "BandeDessinee", etc. selon le vrai type

void Bibliotheque::afficherLivresParCategorie(const string& categorie) const {
    cout << "\n============================================" << endl;
    cout << "  LIVRES DE TYPE: " << categorie << endl;
    cout << "============================================" << endl;
    
    int compteur = 0;
    Noeud<Livre*>* courant = livres.getTete();
    
    while (courant != nullptr) {
        // getType() retourne le vrai type grâce au polymorphisme
        if (courant->donnee->getType() == categorie) {
            cout << endl;
            courant->donnee->afficher();
            compteur++;
        }
        courant = courant->suivant;
    }
    
    if (compteur == 0) {
        cout << "  (aucun livre de ce type)" << endl;
    } else {
        cout << "\nTotal: " << compteur << " livre(s)" << endl;
    }
}

// ============================================================================
// afficherLivresDisponibles() - Affiche les livres libres
// ============================================================================
void Bibliotheque::afficherLivresDisponibles() const {
    cout << "\n============================================" << endl;
    cout << "  LIVRES DISPONIBLES" << endl;
    cout << "============================================" << endl;
    
    int compteur = 0;
    Noeud<Livre*>* courant = livres.getTete();
    
    while (courant != nullptr) {
        if (courant->donnee->estDisponible()) {
            cout << endl;
            courant->donnee->afficher();
            compteur++;
        }
        courant = courant->suivant;
    }
    
    if (compteur == 0) {
        cout << "  (aucun livre disponible)" << endl;
    } else {
        cout << "\nTotal: " << compteur << " livre(s) disponible(s)" << endl;
    }
}

// ============================================================================
// rechercherLivreParCode() - Cherche un livre par son code
// ============================================================================
Livre* Bibliotheque::rechercherLivreParCode(const string& codeLivre) const {
    Noeud<Livre*>* courant = livres.getTete();
    
    while (courant != nullptr) {
        if (courant->donnee->getCode() == codeLivre) {
            return courant->donnee;
        }
        courant = courant->suivant;
    }
    
    return nullptr;  // Non trouvé
}

// ============================================================================
// rechercherLivreParISBN() - Cherche un livre par son ISBN
// ============================================================================
Livre* Bibliotheque::rechercherLivreParISBN(const string& isbn) const {
    Noeud<Livre*>* courant = livres.getTete();
    
    while (courant != nullptr) {
        if (courant->donnee->getIsbn() == isbn) {
            return courant->donnee;
        }
        courant = courant->suivant;
    }
    
    return nullptr;  // Non trouvé
}

// ============================================================================
// acheterLivre() - Ajoute un nouveau livre
// ============================================================================
void Bibliotheque::acheterLivre(Livre* nouveauLivre) {
    livres.ajouter(nouveauLivre);
    cout << ">> Achat OK: \"" << nouveauLivre->getTitre() << "\"" << endl;
}

// ============================================================================
// supprimerLivre() - Supprime un livre (perte ou mise au pilon)
// ============================================================================
void Bibliotheque::supprimerLivre(const string& codeLivre) {
    Livre* livre = rechercherLivreParCode(codeLivre);
    
    if (livre == nullptr) {
        throw LivreNonTrouveException(codeLivre);
    }
    
    string titre = livre->getTitre();
    livres.supprimer(livre);
    delete livre;  // Libérer la mémoire
    
    cout << ">> Suppression OK: \"" << titre << "\"" << endl;
}

// ============================================================================
// inscrireAdherent() - Inscrit un nouvel adhérent
// ============================================================================
void Bibliotheque::inscrireAdherent(Adherent* nouvelAdherent) {
    adherents.ajouter(nouvelAdherent);
    nouvelAdherent->setBibliotheque(this);
    cout << ">> Inscription OK: " << nouvelAdherent->getPrenom() 
         << " " << nouvelAdherent->getNom() << endl;
}

// ============================================================================
// desinscrireAdherent() - Désinscrit un adhérent
// ============================================================================
void Bibliotheque::desinscrireAdherent(const string& numeroAdherent) {
    Adherent* adherent = rechercherAdherent(numeroAdherent);
    
    if (adherent == nullptr) {
        throw AdherentNonTrouveException(numeroAdherent);
    }
    
    // Vérifier qu'il n'a plus de livres
    if (adherent->getNombreEmprunts() > 0) {
        cout << "!! ATTENTION: Cet adherent a encore des livres !" << endl;
    }
    
    string nomComplet = adherent->getPrenom() + " " + adherent->getNom();
    adherents.supprimer(adherent);
    
    cout << ">> Desinscription OK: " << nomComplet << endl;
}

// ============================================================================
// rechercherAdherent() - Cherche un adhérent par son numéro
// ============================================================================
Adherent* Bibliotheque::rechercherAdherent(const string& numeroAdherent) const {
    Noeud<Adherent*>* courant = adherents.getTete();
    
    while (courant != nullptr) {
        if (courant->donnee->getNumeroAdherent() == numeroAdherent) {
            return courant->donnee;
        }
        courant = courant->suivant;
    }
    
    return nullptr;
}

// ============================================================================
// afficherTousLesAdherents() - Affiche tous les adhérents
// ============================================================================
void Bibliotheque::afficherTousLesAdherents() const {
    cout << "\n============================================" << endl;
    cout << "  ADHERENTS: " << nom << endl;
    cout << "============================================" << endl;
    
    if (adherents.getTaille() == 0) {
        cout << "  (aucun adherent)" << endl;
        return;
    }
    
    Noeud<Adherent*>* courant = adherents.getTete();
    while (courant != nullptr) {
        cout << endl;
        courant->donnee->afficher();
        courant = courant->suivant;
    }
    
    cout << "\nTotal: " << adherents.getTaille() << " adherent(s)" << endl;
}

// ============================================================================
// demanderLivre() - Demande un livre à une autre bibliothèque
// ============================================================================
bool Bibliotheque::demanderLivre(Bibliotheque* autreBiblio, const string& isbn) {
    cout << ">> " << nom << " demande le livre ISBN:" << isbn 
         << " a " << autreBiblio->getNom() << endl;
    
    try {
        Livre* livrePrete = autreBiblio->preterLivre(isbn);
        
        if (livrePrete != nullptr) {
            livres.ajouter(livrePrete);
            cout << ">> Pret accepte: \"" << livrePrete->getTitre() << "\"" << endl;
            return true;
        }
    } catch (LivreNonTrouveException& e) {
        cout << e.what() << endl;
    } catch (LivreNonDisponibleException& e) {
        cout << e.what() << endl;
    }
    
    return false;
}

// ============================================================================
// preterLivre() - Prête un livre à une autre bibliothèque
// ============================================================================
Livre* Bibliotheque::preterLivre(const string& isbn) {
    Livre* livre = rechercherLivreParISBN(isbn);
    
    if (livre == nullptr) {
        throw LivreNonTrouveException(isbn);
    }
    
    if (!livre->estDisponible()) {
        throw LivreNonDisponibleException(livre->getCode());
    }
    
    livre->setEtat(PRETE);
    cout << ">> " << nom << " prete: \"" << livre->getTitre() << "\"" << endl;
    
    return livre;
}

// ============================================================================
// rendreLivresPretes() - Rend les livres prêtés non empruntés
// ============================================================================
void Bibliotheque::rendreLivresPretes(Bibliotheque* proprietaire) {
    Noeud<Livre*>* courant = livres.getTete();
    
    while (courant != nullptr) {
        Livre* livre = courant->donnee;
        courant = courant->suivant;  // Avancer AVANT de supprimer
        
        // Si le livre est en état PRETE et n'est pas emprunté
        if (livre->getEtat() == PRETE) {
            livre->setEtat(LIBRE);
            cout << ">> Retour du livre \"" << livre->getTitre() 
                 << "\" a " << proprietaire->getNom() << endl;
        }
    }
}

// ============================================================================
// afficher() - Affiche les infos de la bibliothèque
// ============================================================================
void Bibliotheque::afficher() const {
    cout << "======== BIBLIOTHEQUE ========" << endl;
    cout << "Nom:       " << nom << endl;
    cout << "Adresse:   " << adresse << endl;
    cout << "Code:      " << code << endl;
    cout << "Livres:    " << livres.getTaille() << endl;
    cout << "Adherents: " << adherents.getTaille() << endl;
    cout << "==============================" << endl;
}

// ============================================================================
// GETTERS
// ============================================================================
string Bibliotheque::getNom() const { return nom; }
string Bibliotheque::getAdresse() const { return adresse; }
string Bibliotheque::getCode() const { return code; }
// int Bibliotheque::getNombreLivres() const { return livres.getTaille(); }
// int Bibliotheque::getNombreAdherents() const { return adherents.getTaille(); }
ListeChainee<Livre*>& Bibliotheque::getLivres() { return livres; }
ListeChainee<Adherent*>& Bibliotheque::getAdherents() { return adherents; }

// // ============================================================================
// // SETTERS
// // ============================================================================
// void Bibliotheque::setNom(string nouveauNom) { nom = nouveauNom; }
// void Bibliotheque::setAdresse(string nouvelleAdresse) { adresse = nouvelleAdresse; }

// ============================================================================
// FONCTION AMIE : operator<<
// ============================================================================
ostream& operator<<(ostream& os, const Bibliotheque& biblio) {
    os << "Bibliotheque " << biblio.nom << " [" << biblio.code << "]";
    return os;
}