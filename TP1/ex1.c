#include <stdio.h>

void exchange(int *a, int *b);

void main() {
    int x, y;
    
    printf("Donner x et y \n");
    
    scanf("%d %d", &x, &y);
    
    printf("Avant : x = %d, y = %d\n", x, y);

    exchange(&x, &y);

    printf("Apres : x = %d, y = %d\n", x, y);

}

void exchange(int *a, int *b) {
    int temp = *a;  
    *a = *b;        
    *b = temp;
}