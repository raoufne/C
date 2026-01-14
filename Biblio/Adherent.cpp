// ============================================================================
// Adherent.cpp - Implémentation de la classe Adherent
// ============================================================================

#include "Adherent.h"
#include "Bibliotheque.h"  // Maintenant on peut inclure le fichier complet

// ============================================================================
// INITIALISATION DU MEMBRE STATIQUE
// ============================================================================
int Adherent::compteurAdherents = 0;

// ============================================================================
// CONSTRUCTEUR PAR DEFAUT
// ============================================================================
Adherent::Adherent() {
    nom = "";
    prenom = "";
    adresse = "";
    bibliotheque = nullptr;
    nombreMaxEmprunts = 3;  // Par défaut : 3 livres max
    
    // Générer un numéro unique
    compteurAdherents++;
    numeroAdherent = "ADH" + to_string(compteurAdherents);
}

// ============================================================================
// CONSTRUCTEUR AVEC PARAMETRES
// ============================================================================
Adherent::Adherent(string nom, string prenom, string adresse, 
                   Bibliotheque* biblio, int maxEmprunts) {
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->bibliotheque = biblio;
    this->nombreMaxEmprunts = maxEmprunts;
    
    // Générer un numéro unique
    compteurAdherents++;
    numeroAdherent = "ADH" + to_string(compteurAdherents);
}

// ============================================================================
// DESTRUCTEUR
// ============================================================================
Adherent::~Adherent() {
    // On ne supprime pas les livres (ils appartiennent à la bibliothèque)
    // On vide juste la liste des emprunts
}

// ============================================================================
// emprunterLivre() - Emprunte un livre
// ============================================================================
// CONCEPT : LANCER UNE EXCEPTION avec "throw"

void Adherent::emprunterLivre(const string& codeLivre) {
    // Vérifier que l'adhérent a une bibliothèque
    if (bibliotheque == nullptr) {
        throw BibliothequeException("ERREUR: Adherent sans bibliotheque");
    }
    
    // Vérifier la limite d'emprunts
    if (livresEmpruntes.getTaille() >= nombreMaxEmprunts) {
        throw LimiteEmpruntException(nombreMaxEmprunts);
    }
    
    // Chercher le livre par son code dans la bibliothèque
    Livre* livre = bibliotheque->rechercherLivreParCode(codeLivre);
    
    // Vérifier que le livre existe
    if (livre == nullptr) {
        throw LivreNonTrouveException(codeLivre);
    }
    
    // Vérifier que le livre est disponible
    if (!livre->estDisponible()) {
        throw LivreNonDisponibleException(codeLivre);
    }
    
    // Effectuer l'emprunt
    livre->setEtat(EMPRUNTE);
    livresEmpruntes.ajouter(livre);
    
    cout << ">> Emprunt OK: \"" << livre->getTitre() << "\" par " 
         << prenom << " " << nom << endl;
}

// ============================================================================
// rendreLivre() - Rend un livre
// ============================================================================
void Adherent::rendreLivre(Livre* livre) {
    // Vérifier que l'adhérent a bien ce livre
    bool trouve = false;
    Noeud<Livre*>* courant = livresEmpruntes.getTete();
    
    while (courant != nullptr) {
        if (courant->donnee->getCode() == livre->getCode()) {
            trouve = true;
            break;
        }
        courant = courant->suivant;
    }
    
    if (!trouve) {
        throw LivreNonEmprunteException(livre->getCode());
    }
    
    // Effectuer le retour
    livre->setEtat(LIBRE);
    livresEmpruntes.supprimer(livre);
    
    cout << ">> Retour OK: \"" << livre->getTitre() << "\" par " 
         << prenom << " " << nom << endl;
}

// ============================================================================
// afficher() - Affiche les infos de l'adhérent
// ============================================================================
void Adherent::afficher() const {
    cout << "======== ADHERENT ========" << endl;
    cout << "Numero:  " << numeroAdherent << endl;
    cout << "Nom:     " << nom << endl;
    cout << "Prenom:  " << prenom << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Emprunts:" << livresEmpruntes.getTaille() << "/" << nombreMaxEmprunts << endl;
    cout << "==========================" << endl;
}

// ============================================================================
// afficherLivresEmpruntes() - Liste les livres empruntés
// ============================================================================
void Adherent::afficherLivresEmpruntes() const {
    cout << "== Livres empruntes par " << prenom << " " << nom << " ==" << endl;
    
    if (livresEmpruntes.getTaille() == 0) {
        cout << "   (aucun livre emprunte)" << endl;
        return;
    }
    
    Noeud<Livre*>* courant = livresEmpruntes.getTete();
    int num = 1;
    while (courant != nullptr) {
        cout << "   " << num << ". " << courant->donnee->getTitre() 
             << " [" << courant->donnee->getCode() << "]" << endl;
        courant = courant->suivant;
        num++;
    }
}

// ============================================================================
// GETTERS
// ============================================================================
string Adherent::getNom() const { return nom; }
string Adherent::getPrenom() const { return prenom; }
string Adherent::getAdresse() const { return adresse; }
string Adherent::getNumeroAdherent() const { return numeroAdherent; }
// Bibliotheque* Adherent::getBibliotheque() const { return bibliotheque; }
int Adherent::getNombreEmprunts() const { return livresEmpruntes.getTaille(); }
int Adherent::getNombreMaxEmprunts() const { return nombreMaxEmprunts; }
// ListeChainee<Livre*>& Adherent::getLivresEmpruntes() { return livresEmpruntes; }

// ============================================================================
// SETTERS
// ============================================================================
// void Adherent::setNom(string nouveauNom) { nom = nouveauNom; }
// void Adherent::setPrenom(string nouveauPrenom) { prenom = nouveauPrenom; }
// void Adherent::setAdresse(string nouvelleAdresse) { adresse = nouvelleAdresse; }
void Adherent::setBibliotheque(Bibliotheque* nouvelleBiblio) { bibliotheque = nouvelleBiblio; }
// void Adherent::setNombreMaxEmprunts(int nouveauMax) { nombreMaxEmprunts = nouveauMax; }

// ============================================================================
// METHODE STATIQUE
// ============================================================================
int Adherent::getCompteurAdherents() {
    return compteurAdherents;
}

// ============================================================================
// OPERATEUR ==
// ============================================================================
bool Adherent::operator==(const Adherent& autre) const {
    return (this->numeroAdherent == autre.numeroAdherent);
}

// ============================================================================
// FONCTION AMIE : operator<<
// ============================================================================
ostream& operator<<(ostream& os, const Adherent& adherent) {
    os << adherent.prenom << " " << adherent.nom 
       << " (Num: " << adherent.numeroAdherent << ")";
    return os;
}