#include "Adherent.h"
#include "Bibliotheque.h" 

int Adherent::compteurAdherents = 0;

Adherent::Adherent() {
    nom = "";
    prenom = "";
    adresse = "";
    bibliotheque = nullptr;
    nombreMaxEmprunts = 3; 
    
    compteurAdherents++;
    numeroAdherent = "ADH" + to_string(compteurAdherents);
}

Adherent::Adherent(string nom, string prenom, string adresse, 
                   Bibliotheque* biblio, int maxEmprunts) {
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->bibliotheque = biblio;
    this->nombreMaxEmprunts = maxEmprunts;
    
    compteurAdherents++;
    numeroAdherent = "ADH" + to_string(compteurAdherents);
}

Adherent::~Adherent() {
}

void Adherent::emprunterLivre(const string& codeLivre) {
    if (bibliotheque == nullptr) {
        throw BibliothequeException("ERREUR: Adherent sans bibliotheque");
    }    
    if (livresEmpruntes.getTaille() >= nombreMaxEmprunts) {
        throw LimiteEmpruntException(nombreMaxEmprunts);
    }
    Livre* livre = bibliotheque->rechercherLivreParCode(codeLivre);
    if (livre == nullptr) {
        throw LivreNonTrouveException(codeLivre);
    }
    if (!livre->estDisponible()) {
        throw LivreNonDisponibleException(codeLivre);
    }
    livre->setEtat(EMPRUNTE);
    livresEmpruntes.ajouter(livre);    
    cout << ">> Emprunt OK: \"" << livre->getTitre() << "\" par " 
         << prenom << " " << nom << endl;
}

void Adherent::rendreLivre(Livre* livre) {
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
    livre->setEtat(LIBRE);
    livresEmpruntes.supprimer(livre);
    
    cout << ">> Retour OK: \"" << livre->getTitre() << "\" par " 
         << prenom << " " << nom << endl;
}

void Adherent::afficher() const {
    cout << "======== ADHERENT ========" << endl;
    cout << "Numero:  " << numeroAdherent << endl;
    cout << "Nom:     " << nom << endl;
    cout << "Prenom:  " << prenom << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Emprunts:" << livresEmpruntes.getTaille() << "/" << nombreMaxEmprunts << endl;
    cout << "==========================" << endl;
}
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

string Adherent::getNom() const { return nom; }
string Adherent::getPrenom() const { return prenom; }
string Adherent::getAdresse() const { return adresse; }
string Adherent::getNumeroAdherent() const { return numeroAdherent; }
int Adherent::getNombreEmprunts() const { return livresEmpruntes.getTaille(); }
int Adherent::getNombreMaxEmprunts() const { return nombreMaxEmprunts; }

void Adherent::setBibliotheque(Bibliotheque* nouvelleBiblio) { bibliotheque = nouvelleBiblio; }

int Adherent::getCompteurAdherents() {
    return compteurAdherents;
}

bool Adherent::operator==(const Adherent& autre) const {
    return (this->numeroAdherent == autre.numeroAdherent);
}

ostream& operator<<(ostream& os, const Adherent& adherent) {
    os << adherent.prenom << " " << adherent.nom 
       << " (Num: " << adherent.numeroAdherent << ")";
    return os;
}