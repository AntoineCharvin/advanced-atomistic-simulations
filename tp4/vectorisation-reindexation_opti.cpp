// vectorisation-loops-check.c

/* 
README : vectorise a non-vectorisable loop via a temporary array with re-indexing

compile/run as gcc -O3 -fopt-info-vec -fopt-info-vec-missed vectorisation-reindexation.c  && time ./a.out  
 */

#include <stdio.h>

int main() {
    const int dim = 100000;
    double A[dim];

    // initialise array
    for (int i = 0; i < dim; i++)
        A[i] = 1.0 / (i + 1);

    double S = 0;
    double temp[dim]; // Tableau temporaire pour stocker les résultats intermédiaires

    for (int i = 0; i < dim; i++) {
        temp[i] = (i + 1) * A[i] + 1.0 / (i + 1) * A[dim - i - 1];
    }

    // Calcul de la somme totale
    for (int i = 0; i < dim; i++) {
        S += temp[i];
    }

    printf("S: %lf\n", S); // dummy print

    return 0;
}
