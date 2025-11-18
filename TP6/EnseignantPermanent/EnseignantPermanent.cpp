#include "EnseignantPermanent.h"

EnseignantPermanent::EnseignantPermanent(string nom, string prenom, float salaire,
                                         string bureau, int grade, float primeMensuelle)
    : Personnel(nom, prenom, salaire),
      bureau(bureau), grade(grade), primeMensuelle(primeMensuelle) {}

float EnseignantPermanent::calculSalaire() const {
    return salaire + (grade * primeMensuelle / 100.0f);
}

void EnseignantPermanent::affiche() const {
    Personnel::affiche();
    cout << "Bureau : " << bureau
         << ", Grade : " << grade
         << ", Prime Mensuelle : " << primeMensuelle
         << ", Salaire total : " << calculSalaire() << endl;
}
