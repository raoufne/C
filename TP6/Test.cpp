// use this to compile : 
// cd tp6
// g++ Test.cpp Personne/*.cpp Eleve/*.cpp Personnel/*.cpp PersonnelAdmin/*.cpp EnseignantPermanent/*.cpp EnseignantVacataire/*.cpp ListePersonnel/*.cpp ListePersonnelDyn/*.cpp -o tp6

#include <iostream>
#include "Personne/Personne.h"
#include "Eleve/Eleve.h"
#include "Personnel/Personnel.h"
#include "PersonnelAdmin/PersonnelAdmin.h"
#include "EnseignantPermanent/EnseignantPermanent.h"
#include "EnseignantVacataire/EnseignantVacataire.h"
#include "ListePersonnel/ListePersonnel.h"
#include "ListePersonnelDyn/ListePersonnelDyn.h"


using namespace std;

int main() {

    cout << "=== TEST PERSONNE ===" << endl;
    Personne p("Doe", "John", "Paris", "0102030405");
    p.affiche();

    cout << "\n=== TEST ELEVE ===" << endl;
    Eleve e("Smith", "Alice", "L3 Info", 3.5, "TD2");
    e.affiche();

    // cout << "\n=== TEST PERSONNEL ===" << endl;
    // Personnel pers("Mark", "Tom", 2500);
    // pers.affiche();

    cout << "\n=== TEST PERSONNEL ADMIN ===" << endl;
    PersonnelAdmin pa("Admin", "Paul", 2000, 10, 15);
    pa.affiche();

    cout << "\n=== TEST ENSEIGNANT PERMANENT ===" << endl;
    EnseignantPermanent ep("Prof", "Marie", 3000, "B-123", 5, 200);
    ep.affiche();

    cout << "\n=== TEST ENSEIGNANT VACATAIRE ===" << endl;
    EnseignantVacataire ev("Vac", "Leo", 0, "C-45", 20, 40);
    ev.affiche();

    cout << "\n=== TEST LISTE PERSONNEL (statique) ===" << endl;

    ListePersonnel lp;
    lp.ajoutPersonnel(&pa);
    lp.ajoutPersonnel(&ep);
    lp.ajoutPersonnel(&ev);

    lp.afficherSalaires();

    cout << "\n=== TEST LISTE DYNAMIQUE ===" << endl;

    ListePersonnelDyn lpdyn;

    lpdyn.ajoutPersonnel(&pa);
    lpdyn.ajoutPersonnel(&ep);
    lpdyn.ajoutPersonnel(&ev);

    lpdyn.afficherSalaires();


    return 0;
}
