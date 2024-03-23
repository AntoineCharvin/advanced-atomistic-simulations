#include <stdio.h>
#include <time.h>

int main() {
    const int dim = 1000000;
    double A[dim];

    // initialise array
    for (int i = 0; i < dim; i++)
        A[i] = 1. / (i + 1);

    // measure start time
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // calculate required sum
    double S = 0;
    int half_dim = dim / 2;
    for (int i = 0; i < half_dim; i++) {
        double term1 = (i + 1) * A[i];
        double term2 = (i + 1) * A[dim - i - 1];
        S += term1 + term2;
    }

    // If dim is odd, add the middle term
    if (dim % 2 != 0) {
        S += (half_dim + 1) * A[half_dim];
    }

    // measure end time
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // calculate elapsed time in seconds
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                          (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    printf("Time elapsed: %lf seconds\n", elapsed_time);

    return 0;
}
