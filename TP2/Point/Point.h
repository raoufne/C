#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y, z;
    static int compteur;

public:
    Point();
  
    Point(double x, double y, double z);

    Point(const Point& p);

    ~Point();

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    void saisir();

    void afficher() const;

    void translater(double dx, double dy, double dz);

    double distance(const Point& p) const;

    static int getCompteur();
};

#endif