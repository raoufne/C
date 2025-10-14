#include "Heure.h"

Heure::Heure() : h(0), min(0) {}

Heure::Heure(int h, int min) : h(h), min(min) {
    if (!checkHeure(h, min)) {
        this->h = 0;
        this->min = 0;
    }
}

bool Heure::checkHeure(int h, int min) {
    return (h >= 0 && h < 24 && min >= 0 && min < 60);
}

int Heure::getH() const { return h; }
int Heure::getMin() const { return min; }

void Heure::setH(int h) {
    if (checkHeure(h, min)) this->h = h;
}
void Heure::setMin(int min) {
    if (checkHeure(h, min)) this->min = min;
}

void Heure::saisir() {
    cin >> h >> min;
    if (!checkHeure(h, min)) { h = 0; min = 0; }
}

void Heure::affiche() const {
    cout << (h < 10 ? "0" : "") << h << ":" 
         << (min < 10 ? "0" : "") << min;
}

bool Heure::estEgal(const Heure& hh) const { return h==hh.h && min==hh.min; }

bool Heure::estSuperieur(const Heure& hh) const {
    if(h>hh.h) return true;
    if(h<hh.h) return false;
    return min>hh.min;
}