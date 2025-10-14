#include "Date.h"

int Date::compteur = 0;

Date::Date() : j(1), m(1), a(2000) {
    compteur++;
}

Date::Date(int j, int m, int a) : j(j), m(m), a(a) {
    if (!checkDate(j, m, a)) {
        this->j = 1;
        this->m = 1;
        this->a = 2000;
    }
    compteur++;
}

Date::Date(const Date& d) : j(d.j), m(d.m), a(d.a) {
    compteur++;
}

Date::~Date() {
    compteur--;
}

int Date::getJ() const { return j; }
int Date::getM() const { return m; }
int Date::getA() const { return a; }

void Date::setJ(int j ) { this->j = j; }
void Date::setM(int m) { this->m = m; }
void Date::setA(int a) { this->a = a; }

void Date::saisir() {
    cout << "Entrer Jour : "; cin >> j;
    cout << "Entrer Mois : "; cin >> m;
    cout << "Entrer Annee : "; cin >> a;
    if (!checkDate(j, m, a)) {
        this->j = 1;
        this->m = 1;
        this->a = 2000;
    }
}

void Date::affiche() const {
    cout << j << "/ " << m << "/ " << a ;
}

bool Date::checkDate(int j, int m, int a) {
    if (a < 2000 || a > 2050 || m < 1 || m > 12 || j < 1 || j > 31) return false;

    int joursDansMois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (estBissextile(a)) joursDansMois[1] = 29;

    return j <= joursDansMois[m - 1];
}

bool Date::estBissextile(int a) {
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}


int Date::getCompteur() {
    return compteur;
}

bool Date::estEgal(const Date& d) const {
    return j==d.j && m==d.m && a==d.a;
}

bool Date::estSuperieur(const Date& d) const {
    if(a>d.a) return true;
    if(a<d.a) return false;
    if(m>d.m) return true;
    if(m<d.m) return false;
    return j>d.j;
}