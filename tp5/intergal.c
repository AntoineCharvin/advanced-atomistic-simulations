#include <math.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

// La fonction dont nous voulons calculer l’intégrale
double f(double x) {
    return pow(x, 16.3) * exp(x);
}

int main() {
    int num_trapezoids = 2e7; // Nombre de trapèzes pour l’approximation

    double a = 0.0; // Limite inférieure de l’intervalle d’intégration
    double b = 1.0; // Limite supérieure de l’intervalle d’intégration
    double h = (b - a) / num_trapezoids; // Largeur de chaque trapèze

    double integral_parallel = 0.0;
    double integral_serial = 0.0;

    // Initialisation du nombre de threads à utiliser
    int num_threads = 8;
    omp_set_num_threads(num_threads);

    // Chronomètre pour la version parallèle
    clock_t start_parallel = clock();

    double sum_parallel = 0.0;

    // Utilisation de la directive OpenMP pour paralleliser la boucle
    #pragma omp parallel for reduction(+:sum_parallel)
    for (int i = 1; i <= num_trapezoids; i++) {
        double x1 = a + (i - 1) * h;
        double x2 = a + i * h;
        double aire = 0.5 * (f(x1) + f(x2)) * h;
        sum_parallel += aire;
    }

    // Ajout du résultat partiel à integral_parallel à la fin
    integral_parallel += sum_parallel;

    // Mesurer le temps d'exécution pour la version parallèle
    clock_t end_parallel = clock();
    printf("Temps d'exécution (parallèle) : %f seconds\n", (double)(end_parallel - start_parallel) / CLOCKS_PER_SEC);

    // Chronomètre pour la version non parallèle
    clock_t start_serial = clock();

    // Version non parallèle
    for (int i = 1; i <= num_trapezoids; i++) {
        double x1 = a + (i - 1) * h;
        double x2 = a + i * h;
        double aire = 0.5 * (f(x1) + f(x2)) * h;
        integral_serial += aire;
    }

    // Mesurer le temps d'exécution pour la version non parallèle
    clock_t end_serial = clock();
    printf("Temps d'exécution (non parallèle) : %f seconds\n", (double)(end_serial - start_serial) / CLOCKS_PER_SEC);

    return 0;
}
