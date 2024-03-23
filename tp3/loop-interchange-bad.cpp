#include <stdio.h>
#include <ctime>
#include <iostream>

int main() {
    const int N = 100000;
    int dims[] = {10, 20, 50, 100, 150, 200}; // Les différentes valeurs de dim que vous souhaitez tester

    for (int dim : dims) {
        double a[dim][dim];
        double b[dim][dim];

        std::clock_t start_time = std::clock();
        for (int n = 0; n < N; n++) {
            /* mauvais (en C) : ligne par ligne */
            for (int i = 0; i < dim; i++) { /*ligne i*/
                for (int j = 0; j < dim; j++) { /*colonne j*/
                    b[j][i] = a[j][i];
                }
            }
        }
        std::clock_t end_time = std::clock();
        double temps_total = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        std::cout << "dim = " << dim << ", temps : " << temps_total << " secondes" << std::endl;
    }

    return 0;
}
