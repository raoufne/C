#include "RDV.h"

RDV::RDV() : nombreParticipants(0) {
    participants = new string[10];
    lieu = "Inconnu";
}

RDV::~RDV() {
    delete[] participants;
}

void RDV::affiche() const {
    cout << "Date: "; date.affiche();
    cout << " | Heure: "; heure.affiche();
    cout << " | Lieu: " << lieu;
    cout << " | Participants (" << nombreParticipants << "): ";
    for (int i = 0; i < nombreParticipants; i++)
        cout << participants[i] << " ";
    cout << endl;
}

void RDV::saisieParticipants() {
    cout << "Nombre de participants (max 10) : ";
    cin >> nombreParticipants;
    if (nombreParticipants > 10) nombreParticipants = 10;
    for (int i = 0; i < nombreParticipants; i++) {
        cout << "Participant " << i+1 << ": ";
        cin >> participants[i];
    }
}

void RDV::saisieLieu() {
    cout << "Lieu : ";
    cin >> lieu;
}

void RDV::saisie() {
    cout << "Saisir la date (j m a) : ";
    date.saisir();
    cout << "Saisir l'heure (h min) : ";
    heure.saisir();
    saisieLieu();
    saisieParticipants();
}

void RDV::setDate(const Date& d) { date = d; }
void RDV::setHeure(const Heure& h) { heure = h; }
void RDV::setLieu(const string& l) { lieu = l; }
void RDV::setNombreDeParticipants(int n) { nombreParticipants = n; }
void RDV::setParticipants(string* ps) { participants = ps; }
void RDV::setParticipant(int i, string s) { participants[i] = s; }

bool RDV::estCompatibleAvec(const RDV& r) {
    return !(date.getJ() == r.date.getJ() &&
             date.getM() == r.date.getM() &&
             date.getA() == r.date.getA() &&
             heure.getH() == r.heure.getH() &&
             heure.getMin() == r.heure.getMin());
}
