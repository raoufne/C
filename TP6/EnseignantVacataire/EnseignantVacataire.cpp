#include "EnseignantVacataire.h"

EnseignantVacataire::EnseignantVacataire(string nom, string prenom, float salaire,
                                         string casier, int nbreHeures, float taux)
    : Personnel(nom, prenom, salaire),
      casier(casier), nbreHeures(nbreHeures), taux(taux) {}

float EnseignantVacataire::calculSalaire() const {
    return nbreHeures * taux;
}

void EnseignantVacataire::affiche() const {
    Personnel::affiche();
    cout << "Casier : " << casier
         << ", Heures : " << nbreHeures
         << ", Taux : " << taux
         << ", Salaire total : " << calculSalaire() << endl;
}
