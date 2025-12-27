// ============================================================================
// Livre.cpp - Implémentation de la classe Livre
// ============================================================================
// Ce fichier contient le CODE des méthodes déclarées dans Livre.h
// ============================================================================

#include "Livre.h"

// ============================================================================
// INITIALISATION DU MEMBRE STATIQUE
// ============================================================================
// OBLIGATOIRE : les membres statiques doivent être initialisés
// EN DEHORS de la classe, dans le fichier .cpp
// Syntaxe : Type NomClasse::nomVariable = valeur;
int Livre::nombreTotalLivres = 0;

// ============================================================================
// CONSTRUCTEUR PAR DEFAUT
// ============================================================================
Livre::Livre() {
    code = "";
    auteur = "";
    titre = "";
    editeur = "";
    isbn = "";
    publicCible = TOUT_PUBLIC;
    etat = LIBRE;
    
    // On incrémente le compteur statique
    nombreTotalLivres++;
}

// ============================================================================
// CONSTRUCTEUR AVEC PARAMETRES
// ============================================================================
Livre::Livre(string code, string auteur, string titre, 
             string editeur, string isbn, Public publicCible) {
    
    // "this->" permet de distinguer l'attribut du paramètre
    // quand ils ont le même nom
    this->code = code;
    this->auteur = auteur;
    this->titre = titre;
    this->editeur = editeur;
    this->isbn = isbn;
    this->publicCible = publicCible;
    this->etat = LIBRE;  // Un nouveau livre est toujours libre
    
    nombreTotalLivres++;
}

// ============================================================================
// DESTRUCTEUR VIRTUEL
// ============================================================================
Livre::~Livre() {
    // On décrémente le compteur quand un livre est détruit
    nombreTotalLivres--;
}

// ============================================================================
// getType() - Retourne le type de livre
// ============================================================================
// Méthode virtuelle : sera redéfinie dans les classes filles
string Livre::getType() const {
    return "Livre";
}

// ============================================================================
// GETTERS - Méthodes pour lire les attributs
// ============================================================================

string Livre::getCode() const {
    return code;
}

string Livre::getAuteur() const {
    return auteur;
}

string Livre::getTitre() const {
    return titre;
}

string Livre::getEditeur() const {
    return editeur;
}

string Livre::getIsbn() const {
    return isbn;
}

Public Livre::getPublicCible() const {
    return publicCible;
}

Etat Livre::getEtat() const {
    return etat;
}

// ============================================================================
// SETTER - Modifier l'état du livre
// ============================================================================
void Livre::setEtat(Etat nouvelEtat) {
    etat = nouvelEtat;
}

// ============================================================================
// METHODE STATIQUE
// ============================================================================
// Note : on ne remet PAS "static" dans le .cpp, seulement dans le .h
int Livre::getNombreTotalLivres() {
    return nombreTotalLivres;
}

// ============================================================================
// etatToString() - Convertit l'enum Etat en texte lisible
// ============================================================================
string Livre::etatToString() const {
    switch(etat) {
        case LIBRE:     return "Libre";
        case EMPRUNTE:  return "Emprunte";
        case PRETE:     return "Prete";
        default:        return "Inconnu";
    }
}

// ============================================================================
// publicToString() - Convertit l'enum Public en texte lisible
// ============================================================================
string Livre::publicToString() const {
    switch(publicCible) {
        case ADULTE:      return "Adulte";
        case ADOS:        return "Adolescents";
        case JEUNESSE:    return "Jeunesse";
        case TOUT_PUBLIC: return "Tout public";
        default:          return "Inconnu";
    }
}

// ============================================================================
// estDisponible() - Vérifie si le livre peut être emprunté
// ============================================================================
bool Livre::estDisponible() const {
    return (etat == LIBRE);
}

// ============================================================================
// REDEFINITION OPERATEUR ==
// ============================================================================
// Permet de comparer deux livres avec : if (livre1 == livre2)
// Deux livres sont égaux s'ils ont le même code
bool Livre::operator==(const Livre& autre) const {
    return (this->code == autre.code);
}

// ============================================================================
// FONCTION AMIE : operator<<
// ============================================================================
// ATTENTION : ce n'est PAS une méthode de la classe (pas de Livre::)
// C'est une fonction externe qui a le droit d'accéder aux attributs protégés
// Permet d'écrire : cout << monLivre;
ostream& operator<<(ostream& os, const Livre& livre) {
    os << "Code: " << livre.code << " | ";
    os << "Titre: " << livre.titre << " | ";
    os << "Auteur: " << livre.auteur << " | ";
    os << "Etat: " << livre.etatToString();
    return os;  // On retourne os pour permettre le chaînage : cout << l1 << l2;
}