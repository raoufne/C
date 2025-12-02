#include <iostream>
#include "Vecteur.h"
using namespace std;

int main() {
    Vecteur<int> v(5);

    for (int i = 0; i < v.size(); i++)
        v[i] = i * 10;

    cout << "Contenu du vecteur : ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << "\nAcces a v[2] = " << v[2] << endl;

    return 0;
}
