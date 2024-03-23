#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

int main( int argc, char * argv[] )
{
    // Définir différentes valeurs de numOperations à tester
    std::vector<int> numOperationsValues = {1000, 10000, 100000, 1000000, 10000000};

    // Stocker les temps d'exécution
    std::vector<double> executionTimes;


    int j;
    unsigned long somme = 0;
    float a = 1.3;
    float b = 3.7;
    int c = 4;
    int d = 8;
    for( j=0; j<10; j++ ) {
        clock_t begin = clock();
        int long i;
        for( i=0; i<100000000; i++ ) {
        float e = a/b;
        }
        clock_t end = clock();
        somme += (end -  begin) * 1000 / CLOCKS_PER_SEC;
    }
    unsigned long millis = somme / j;
    printf( "Temps moyen float / : %ld ms\n", millis );
    somme = 0;
    for( j=0; j<10; j++ ) {
        clock_t begin = clock();
        int long i;
        for( i=0; i<100000000; i++ ) {
        float f = c/d;
        }
        clock_t end = clock();
        somme += (end -  begin) * 1000 / CLOCKS_PER_SEC;
    }
    millis = somme / j;
    printf( "Temps moyen int / : %ld ms\n", millis );
    somme = 0;
    for( j=0; j<10; j++ ) {
        clock_t begin = clock();
        int long i;
        for( i=0; i<100000000; i++ ) {
        float g = a*b;
        }
        clock_t end = clock();
        somme += (end -  begin) * 1000 / CLOCKS_PER_SEC;
    }
    millis = somme / j;
    printf( "Temps moyen float * : %ld ms\n", millis );
    somme = 0;
    for( j=0; j<10; j++ ) {
        clock_t begin = clock();
        int long i;
        for( i=0; i<100000000; i++ ) {
        float h = c*d;
        }
        clock_t end = clock();
        somme += (end -  begin) * 1000 / CLOCKS_PER_SEC;
    }
    millis = somme / j;
    printf( "Temps moyen int * : %ld ms\n", millis );

    return 0;
}
