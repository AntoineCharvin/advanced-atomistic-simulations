#include <stdio.h>
#include <ctime>
#include <iostream>

int main() {
    long int niter = 100000;
    long int ndims[] = {100, 200, 500, 1000, 1500, 2000}; // Les différentes valeurs de ndim que vous souhaitez tester

    for (long int ndim : ndims) {
        int a[ndim], b[ndim];

        std::clock_t start_time = std::clock();
        for (long int n = 0; n < niter; n++) {
            long int i;

            for (i = 0; i < ndim; i++)
                a[i] = 1;

            for (i = 0; i < ndim; i++)
                b[i] = 2;
        }
        std::clock_t end_time = std::clock();
        double temps_total = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        std::cout << "ndim = " << ndim << ", temps : " << temps_total << " secondes" << std::endl;
    }

    return 0;
}
