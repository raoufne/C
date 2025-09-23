#include <stdio.h>

#define MAX 10   

void saisir(int mat[MAX][MAX], int n);
void afficher(int mat[MAX][MAX], int n);
void additionner(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int n);
void multiplier(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int n);
int menu();



void main() {
    int n, choix;
    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];

    printf("Donner la taille de la matrice (<= %d): ", MAX);
    scanf("%d", &n);

    printf("\n--- Matrice A ---\n");
    saisir(A, n);

    printf("\n--- Matrice B ---\n");
    saisir(B, n);

    do {
        choix = menu();
        switch (choix) {
            case 1:
                additionner(A, B, R, n);
                printf("\nRésultat de A + B :\n");
                afficher(R, n);
                break;
            case 2:
                multiplier(A, B, R, n);
                printf("\nRésultat de A * B :\n");
                afficher(R, n);
                break;
            case 3:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide !\n");
        }
    } while (choix != 3);
}

void saisir(int mat[MAX][MAX], int n) {
    printf("Saisir les elements de la matrice (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}


void afficher(int mat[MAX][MAX], int n) {
    printf("Matrice %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", mat[i][j]);
        }
        printf("\n");
    }
}


void additionner(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}


void multiplier(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}


int menu() {
    int choix;
    printf("\n=== MENU ===\n");
    printf("1. Additionner deux matrices\n");
    printf("2. Multiplier deux matrices\n");
    printf("3. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}