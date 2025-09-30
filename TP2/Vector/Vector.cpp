#include "Vector.h"

int Vector::compteur = 0;

Vector::Vector() : dimension(0), coords(nullptr) {
    compteur++;
}

Vector::Vector(int dim) : dimension(dim) {
    coords = new double[dim];
    for (int i = 0; i < dim; i++) coords[i] = 0;
    compteur++;
}

Vector::Vector(int dim, const double values[]) : dimension(dim) {
    coords = new double[dim];
    for (int i = 0; i < dim; i++) coords[i] = values[i];
    compteur++;
}

Vector::Vector(const Vector& v) : dimension(v.dimension) {
    coords = new double[dimension];
    for (int i = 0; i < dimension; i++) coords[i] = v.coords[i];
    compteur++;
}

Vector::~Vector() {
    delete[] coords;
    compteur--;
}

double Vector::getCoordinate(int index) const {
    if (index < 0 || index >= dimension) {
        cerr << "Index hors limites !" << endl;
        return 0;
    }
    return coords[index];
}

void Vector::setCoordinate(int index, double value) {
    if (index < 0 || index >= dimension) {
        cerr << "Index hors limites !" << endl;
        return;
    }
    coords[index] = value;
}

void Vector::afficher() const {
    cout << "[";
    for (int i = 0; i < dimension; i++) {
        cout << coords[i];
        if (i < dimension - 1) cout << ", ";
    }
    cout << "]";
}

double Vector::norme() const {
    double sum = 0;
    for (int i = 0; i < dimension; i++) sum += coords[i] * coords[i];
    return sqrt(sum);
}

bool Vector::egal(const Vector& v) const {
    if (dimension != v.dimension) return false;
    for (int i = 0; i < dimension; i++) {
        if (coords[i] != v.coords[i]) return false;
    }
    return true;
}

double Vector::produitScalaire(const Vector& v) const {
    if (dimension != v.dimension) {
        cerr << "Dimensions incompatibles !" << endl;
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < dimension; i++) sum += coords[i] * v.coords[i];
    return sum;
}

Vector Vector::operator*(double k) const {
    Vector result(dimension);
    for (int i = 0; i < dimension; i++) result.coords[i] = coords[i] * k;
    return result;
}

Vector Vector::operator+(const Vector& v) const {
    if (dimension != v.dimension) {
        cerr << "Dimensions incompatibles !" << endl;
        return Vector();
    }
    Vector result(dimension);
    for (int i = 0; i < dimension; i++) result.coords[i] = coords[i] + v.coords[i];
    return result;
}

int Vector::getCompteur() {
    return compteur;
}
