#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cmath>
using namespace std;

class Date {
private:
    int j, m, a;
    static int compteur;
    bool checkDate(int j, int m, int a);
    bool estBissextile(int a);

public:
    Date();
  
    Date(int j, int m, int a);

    Date(const Date& d);

    ~Date();

    int getJ() const;
    int getM() const;
    int getA() const;

    void setJ(int j);
    void setM(int m);
    void setA(int a);

    void saisir();

    void affiche() const;

    static int getCompteur();
};

#endif