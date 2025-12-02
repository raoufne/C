#include <iostream>
using namespace std;

template <class T>
T somme(T tab[], int n) {
    T s = T();  
    for(int i = 0; i < n; i++)
        s += tab[i];
    return s;
}

int main() {
    int ti[] = {1,2,3,4};
    float tf[] = {1.5, 2.5, 3.5};
    char tc[] = {'a','b','c'};

    cout << somme(ti, 4) << endl;
    cout << somme(tf, 3) << endl;
    cout << somme(tc, 3) << endl;

    return 0;
}