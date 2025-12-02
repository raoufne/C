#include <iostream>
using namespace std;

template <class T>
int indiceMin(T tab[], int n) {
    int index = 0;
    for(int i = 1; i < n; i++)
        if(tab[i] < tab[index])
            index = i;
    return index;
}

template <class T, class U>
int indiceMin(T tab1[], U tab2[], int n) {
    int index = 0;
    for(int i = 1; i < n; i++) {
        if (tab1[i] < tab1[index])
            index = i;
        else if (tab1[i] == tab1[index] && tab2[i] < tab2[index])
            index = i;
    }
    return index;
}


int main() {
    int a[] = {1, 2, 8, 1, 1};
    float b[] = {9.5, 7.0, 8.8, 3.1, 5.0};

    cout << "Tableau a: [1 2 8 1 1]" << endl;
    cout << "Indice min(a) = " << indiceMin(a, 5) << endl;

    cout << "\nAvec second tableau (b): [9.5 7.0 8.8 3.1 5.0]" << endl;
    cout << "Indice min(a, b) = " << indiceMin(a, b, 5) << endl;

    return 0;
}
