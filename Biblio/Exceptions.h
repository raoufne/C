// ============================================================================
// Exceptions.h - Classes d'exceptions personnalisées
// ============================================================================
// CONCEPT : EXCEPTIONS
// Une exception permet de gérer les erreurs de manière propre.
// Quand une erreur se produit, on "lance" (throw) une exception.
// Le code appelant peut "attraper" (catch) cette exception.
// ============================================================================
// Exemple d'utilisation :
//
// try {
//     adherent.emprunterLivre(livre);  // Peut lancer une exception
// } catch (LimiteEmpruntException& e) {
//     cout << e.what() << endl;        // Affiche le message d'erreur
// }
// ============================================================================

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>  // Classe de base "exception"
#include <string>
using namespace std;

// ============================================================================
// CLASSE DE BASE : BibliothequeException
// ============================================================================
// Toutes nos exceptions héritent de cette classe
// qui elle-même hérite de "exception" (classe standard C++)

class BibliothequeException : public exception {

protected:
    string message;  // Message d'erreur

public:
    // Constructeur avec message
    BibliothequeException(const string& msg) : message(msg) {}
    
    // what() retourne le message d'erreur
    // "noexcept" = cette méthode ne lance pas d'exception
    // "override" = on redéfinit la méthode de la classe mère
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

// ============================================================================
// EXCEPTION : Livre non trouvé
// ============================================================================
class LivreNonTrouveException : public BibliothequeException {
public:
    LivreNonTrouveException(const string& code) 
        : BibliothequeException("ERREUR: Livre non trouve (code: " + code + ")") {}
};

// ============================================================================
// EXCEPTION : Livre non disponible (déjà emprunté ou prêté)
// ============================================================================
class LivreNonDisponibleException : public BibliothequeException {
public:
    LivreNonDisponibleException(const string& code) 
        : BibliothequeException("ERREUR: Livre non disponible (code: " + code + ")") {}
};

// ============================================================================
// EXCEPTION : Limite d'emprunt atteinte
// ============================================================================
class LimiteEmpruntException : public BibliothequeException {
public:
    LimiteEmpruntException(int limite) 
        : BibliothequeException("ERREUR: Limite d'emprunt atteinte (" + to_string(limite) + " livres max)") {}
};

// ============================================================================
// EXCEPTION : Adhérent non trouvé
// ============================================================================
class AdherentNonTrouveException : public BibliothequeException {
public:
    AdherentNonTrouveException(const string& numero) 
        : BibliothequeException("ERREUR: Adherent non trouve (numero: " + numero + ")") {}
};

// ============================================================================
// EXCEPTION : Livre pas emprunté par cet adhérent (pour le retour)
// ============================================================================
class LivreNonEmprunteException : public BibliothequeException {
public:
    LivreNonEmprunteException(const string& code) 
        : BibliothequeException("ERREUR: Ce livre n'est pas emprunte par vous (code: " + code + ")") {}
};

// ============================================================================
// EXCEPTION : Bibliothèque non trouvée
// ============================================================================
class BibliothequeNonTrouveeException : public BibliothequeException {
public:
    BibliothequeNonTrouveeException(const string& code) 
        : BibliothequeException("ERREUR: Bibliotheque non trouvee (code: " + code + ")") {}
};

#endif // EXCEPTIONS_H