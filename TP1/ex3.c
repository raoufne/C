#include <stdio.h>
#include <stdlib.h>

int** AllouerMatrice(int n, int m);
int** SaisirMatrice(int* n, int* m);
void AfficherMatrice(int** mat, int n, int m);
void TrouvePointsClos(int** mat, int n, int m);



void main() {
    int n, m;
    int** mat = SaisirMatrice(&n, &m);

    printf("Matrice saisie :\n");
    AfficherMatrice(mat, n, m);

    TrouvePointsClos(mat, n, m);

    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
}

int** AllouerMatrice(int n, int m) {
    int** mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*)malloc(m * sizeof(int));
    }
    return mat;
}

int** SaisirMatrice(int* n, int* m) {
    printf("Donner le nombre de lignes: ");
    scanf("%d", n);
    printf("Donner le nombre de colonnes: ");
    scanf("%d", m);

    int** mat = AllouerMatrice(*n, *m);

    printf("Saisir les elements de la matrice (%d x %d):\n", *n, *m);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    return mat;
}

void AfficherMatrice(int** mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d ", mat[i][j]);
        }
        printf("\n");
    }
}

int** MaxLigne(int** mat, int n, int m) {
    int** maxL = AllouerMatrice(n, m);

    for (int i = 0; i < n; i++) {
        int max = mat[i][0];
        for (int j = 1; j < m; j++) {
            if (mat[i][j] > max)
                max = mat[i][j];
        }
        for (int j = 0; j < m; j++) {
            maxL[i][j] = (mat[i][j] == max) ? 1 : 0;
        }
    }
    return maxL;
}

int** MinColonne(int** mat, int n, int m) {
    int** minC = AllouerMatrice(n, m);

    for (int j = 0; j < m; j++) {
        int min = mat[0][j];
        for (int i = 1; i < n; i++) {
            if (mat[i][j] < min)
                min = mat[i][j];
        }
        for (int i = 0; i < n; i++) {
            minC[i][j] = (mat[i][j] == min) ? 1 : 0;
        }
    }
    return minC;
}

void TrouvePointsClos(int** mat, int n, int m) {
    int** maxL = MaxLigne(mat, n, m);
    int** minC = MinColonne(mat, n, m);

    printf("Points Clos MaxLigne ---\n");
    int trouve = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maxL[i][j] == 1 && minC[i][j] == 1) {
                printf("Valeur %d à la position (ligne=%d, colonne=%d)\n", mat[i][j], i, j);
                trouve = 1;
            }
        }
    }
    if (!trouve) {
        printf("Aucun Point Clos trouvé.\n");
    }
}