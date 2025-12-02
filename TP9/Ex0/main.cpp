#include <iostream>
using namespace std;

template<class T, class U> void fct(T a, U b) { 
cout << "je suis la fonction 1" << endl; 
} 
template<class T, class U> void fct(T * a, U b) { 
cout << "je suis la fonction 2" << endl; 
} 
template<class T> void fct(T, T, T) { 
cout << "je suis la fonction 3" << endl; 
} 
void fct(int a, float b) { 
cout << "Je suis la fonction 4" << endl; 
}

int main() {
    int n=0, p=0, q=0;
    float x=0.0, y=0.0;
    double z=0.0;

    fct(n, p);          
    fct(x, y);          
    fct(n, x);          
    fct(n, z);          
    fct(&n, p);         
    fct(&n, x);         
    fct(&n, &p, &q);    

    return 0; 
}

