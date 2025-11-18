#include "PersonnelAdmin.h"

PersonnelAdmin::PersonnelAdmin(string nom, string prenom, float salaire,
                               int heuresSup, float taux)
   : Personnel(nom, prenom, salaire), heuresSup(heuresSup), taux(taux) {}

float PersonnelAdmin::calculSalaire() const {
    return salaire + heuresSup * taux;
}

void PersonnelAdmin::affiche() const {
    Personnel::affiche();
    cout << "Heures sup : " << heuresSup
         << ", Taux : " << taux
         << ", Salaire total : " << calculSalaire() << endl;
}
