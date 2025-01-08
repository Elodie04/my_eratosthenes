#include <stdio.h>

void my_eratosthenes(int n) {
    // Si n est inférieur à 2, il n'y a pas de nombres premiers à afficher
    if (n < 2) {
        printf("Aucun nombre premier jusqu'à %d\n", n);
        return;
    }

    // Création d'un tableau pour marquer les nombres premiers
    int tableau[n + 1];

    // 1 signifie que le nombre est supposé premier
    for (int i = 0; i <= n; i++) {
        tableau[i] = 1;
    }

    // 0 et 1 ne sont pas premiers
    tableau[0] = 0;
    tableau[1] = 0;

    // pour chaque nombre p, on marque ses multiples comme non premiers
    for (int p = 2; p * p <= n; p++) {
        if (tableau[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                tableau[multiple] = 0;
            }
        }
    }

    // Affichage des nombres premiers
    printf("Nombres premiers jusqu'a %d : ", n);
    for (int i = 0; i <= n; i++) {
        if (tableau[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n = 50;
    my_eratosthenes(n);
    return 0;
}
