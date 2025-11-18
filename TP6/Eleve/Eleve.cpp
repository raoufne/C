#include "Eleve.h"

Eleve::Eleve(string nom, string prenom, string promotion, float GPA, string groupeTD)
    : Personne(nom, prenom), promotion(promotion), groupeTD(groupeTD), GPA(GPA) {}

void Eleve::setPromotion(string p) { promotion = p; }
void Eleve::setGroupeTD(string g) { groupeTD = g; }
void Eleve::setGPA(float g) { GPA = g; }

string Eleve::getPromotion() const { return promotion; }
string Eleve::getGroupeTD() const { return groupeTD; }
float Eleve::getGPA() const { return GPA; }

void Eleve::affiche() const {
    Personne::affiche();
    cout << "Promotion : " << promotion
         << ", Groupe TD : " << groupeTD
         << ", GPA : " << GPA << endl;
}
