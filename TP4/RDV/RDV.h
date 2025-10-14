#ifndef RDV_H
#define RDV_H

#include <iostream>
#include <string>
#include "../Date/Date.h"
#include "../Heure/Heure.h"
using namespace std;

class RDV {
private:
    Date date;
    Heure heure;
    string lieu;
    int nombreParticipants;
    string* participants;

public:
    RDV(); 
    ~RDV();

    void affiche() const;
    void saisieParticipants();
    void saisieLieu();
    void saisie();

    void setDate(const Date& d);
    void setHeure(const Heure& h);
    void setLieu(const string& l);
    void setNombreDeParticipants(int n);
    void setParticipants(string* ps);
    void setParticipant(int i, string s);

    bool estCompatibleAvec(const RDV& r);
    bool estEgal(const RDV& r) const;
};

#endif
