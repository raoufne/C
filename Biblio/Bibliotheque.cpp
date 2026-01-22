#include "Bibliotheque.h"
#include "Adherent.h"

Bibliotheque::Bibliotheque() {
    nom = "";
    adresse = "";
    code = "";
}

Bibliotheque::Bibliotheque(string nom, string adresse, string code) {
    this->nom = nom;
    this->adresse = adresse;
    this->code = code;
}

Bibliotheque::~Bibliotheque() {
}

void Bibliotheque::afficherTousLesLivres() const {
    cout << "\n============================================" << endl;
    cout << "  CATALOGUE: " << nom << endl;
    cout << "============================================" << endl;
    
    if (livres.getTaille() == 0) {
        cout << "  (aucun livre)" << endl;
        return;
    }
    
    Noeud<Livre*>* courant = livres.getTete();
    while (courant != nullptr) {
        cout << endl;
        courant->donnee->afficher();
        courant = courant->suivant;
    }
    
    cout << "\nTotal: " << livres.getTaille() << " livre(s)" << endl;
}

void Bibliotheque::afficherLivresParCategorie(const string& categorie) const {
    cout << "\n============================================" << endl;
    cout << "  LIVRES DE TYPE: " << categorie << endl;
    cout << "============================================" << endl;
    
    int compteur = 0;
    Noeud<Livre*>* courant = livres.getTete();
    
    while (courant != nullptr) {
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

Livre* Bibliotheque::rechercherLivreParCode(const string& codeLivre) const {
    Noeud<Livre*>* courant = livres.getTete();
    
    while (courant != nullptr) {
        if (courant->donnee->getCode() == codeLivre) {
            return courant->donnee;
        }
        courant = courant->suivant;
    }
    
    return nullptr; 
}

Livre* Bibliotheque::rechercherLivreParISBN(const string& isbn) const {
    Noeud<Livre*>* courant = livres.getTete();
    
    while (courant != nullptr) {
        if (courant->donnee->getIsbn() == isbn) {
            return courant->donnee;
        }
        courant = courant->suivant;
    }
    
    return nullptr;  
}

void Bibliotheque::acheterLivre(Livre* nouveauLivre) {
    livres.ajouter(nouveauLivre);
    cout << ">> Achat OK: \"" << nouveauLivre->getTitre() << "\"" << endl;
}

void Bibliotheque::supprimerLivre(const string& codeLivre) {
    Livre* livre = rechercherLivreParCode(codeLivre);
    
    if (livre == nullptr) {
        throw LivreNonTrouveException(codeLivre);
    }
    
    string titre = livre->getTitre();
    livres.supprimer(livre);
    delete livre; 
    
    cout << ">> Suppression OK: \"" << titre << "\"" << endl;
}

void Bibliotheque::inscrireAdherent(Adherent* nouvelAdherent) {
    adherents.ajouter(nouvelAdherent);
    nouvelAdherent->setBibliotheque(this);
    cout << ">> Inscription OK: " << nouvelAdherent->getPrenom() 
         << " " << nouvelAdherent->getNom() << endl;
}

void Bibliotheque::desinscrireAdherent(const string& numeroAdherent) {
    Adherent* adherent = rechercherAdherent(numeroAdherent);
    
    if (adherent == nullptr) {
        throw AdherentNonTrouveException(numeroAdherent);
    }
    
    if (adherent->getNombreEmprunts() > 0) {
        cout << "!! ATTENTION: Cet adherent a encore des livres !" << endl;
    }
    
    string nomComplet = adherent->getPrenom() + " " + adherent->getNom();
    adherents.supprimer(adherent);
    
    cout << ">> Desinscription OK: " << nomComplet << endl;
}

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

bool Bibliotheque::demanderLivre(Bibliotheque* autreBiblio, const string& isbn) {
    cout << ">> " << nom << " demande le livre ISBN:" << isbn 
         << " a " << autreBiblio->getNom() << endl;
    
    try {
        Livre* livrePrete = autreBiblio->preterLivre(isbn);
        if (livrePrete != nullptr) {
            autreBiblio->getLivres().supprimer(livrePrete);
            
            livres.ajouter(livrePrete);
            cout << ">> Pret accepte: \"" << livrePrete->getTitre() << "\"" << endl;
            return true;
        }
    } catch (BibliothequeException& e) {
        cout << e.what() << endl;
    }
    return false;
}

Livre* Bibliotheque::preterLivre(const string& isbn) {
    Livre* livre = rechercherLivreParISBN(isbn);
    if (livre == nullptr) throw LivreNonTrouveException(isbn);
    if (!livre->estDisponible()) throw LivreNonDisponibleException(livre->getCode());
    
    livre->setEtat(PRETE);
    cout << ">> " << nom << " prete: \"" << livre->getTitre() << "\"" << endl;
    return livre;
}

void Bibliotheque::rendreLivresPretes(Bibliotheque* proprietaire) {
    ListeChainee<Livre*> livresARendre;
    
    Noeud<Livre*>* courant = livres.getTete();
    while (courant != nullptr) {
        if (courant->donnee->getEtat() == PRETE) {
            livresARendre.ajouter(courant->donnee);
        }
        courant = courant->suivant;
    }
    
    courant = livresARendre.getTete();
    while (courant != nullptr) {
        Livre* livre = courant->donnee;
        
        livres.supprimer(livre);
        
        livre->setEtat(LIBRE);
        
        proprietaire->getLivres().ajouter(livre);
        
        cout << ">> Retour du livre \"" << livre->getTitre() 
             << "\" a " << proprietaire->getNom() << endl;
        
        courant = courant->suivant;
    }
}

void Bibliotheque::afficher() const {
    cout << "======== BIBLIOTHEQUE ========" << endl;
    cout << "Nom:       " << nom << endl;
    cout << "Adresse:   " << adresse << endl;
    cout << "Code:      " << code << endl;
    cout << "Livres:    " << livres.getTaille() << endl;
    cout << "Adherents: " << adherents.getTaille() << endl;
    cout << "==============================" << endl;
}

string Bibliotheque::getNom() const { return nom; }
string Bibliotheque::getAdresse() const { return adresse; }
string Bibliotheque::getCode() const { return code; }

ListeChainee<Livre*>& Bibliotheque::getLivres() { return livres; }
ListeChainee<Adherent*>& Bibliotheque::getAdherents() { return adherents; }

ostream& operator<<(ostream& os, const Bibliotheque& biblio) {
    os << "Bibliotheque " << biblio.nom << " [" << biblio.code << "]";
    return os;
}