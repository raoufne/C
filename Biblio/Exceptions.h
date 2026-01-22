#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

class BibliothequeException : public exception {

protected:
    string message;

public:
    BibliothequeException(const string& msg) : message(msg) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class LivreNonTrouveException : public BibliothequeException {
public:
    LivreNonTrouveException(const string& code) 
        : BibliothequeException("ERREUR: Livre non trouve (code: " + code + ")") {}
};

class LivreNonDisponibleException : public BibliothequeException {
public:
    LivreNonDisponibleException(const string& code) 
        : BibliothequeException("ERREUR: Livre non disponible (code: " + code + ")") {}
};

class LimiteEmpruntException : public BibliothequeException {
public:
    LimiteEmpruntException(int limite) 
        : BibliothequeException("ERREUR: Limite d'emprunt atteinte (" + to_string(limite) + " livres max)") {}
};

class AdherentNonTrouveException : public BibliothequeException {
public:
    AdherentNonTrouveException(const string& numero) 
        : BibliothequeException("ERREUR: Adherent non trouve (numero: " + numero + ")") {}
};

class LivreNonEmprunteException : public BibliothequeException {
public:
    LivreNonEmprunteException(const string& code) 
        : BibliothequeException("ERREUR: Ce livre n'est pas emprunte par vous (code: " + code + ")") {}
};

class BibliothequeNonTrouveeException : public BibliothequeException {
public:
    BibliothequeNonTrouveeException(const string& code) 
        : BibliothequeException("ERREUR: Bibliotheque non trouvee (code: " + code + ")") {}
};

#endif