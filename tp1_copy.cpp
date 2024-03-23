#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <random>
#include <iostream>

int main( int argc, char * argv[] )
{
    // Créer un générateur de nombres aléatoires
    std::default_random_engine generator;

    // Créer des distributions pour générer des nombres aléatoires dans des plages spécifiques
    std::uniform_real_distribution<float> distribution(2.0, 99.0);



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
            float num1 = distribution(generator);
            float num2 = distribution(generator);
            // Effectuer une opération d'addition simple avec des nombres aléatoires
            float result = num1 / num2;
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
            float num1 = distribution(generator);
            float num2 = distribution(generator);
            // Effectuer une opération d'addition simple avec des nombres aléatoires
            float result = num1 / num2;
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
            float num1 = distribution(generator);
            float num2 = distribution(generator);
            // Effectuer une opération d'addition simple avec des nombres aléatoires
            float result = num1 * num2;
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
            float num1 = distribution(generator);
            float num2 = distribution(generator);
            // Effectuer une opération d'addition simple avec des nombres aléatoires
            float result = num1 * num2;
        }
        clock_t end = clock();
        somme += (end -  begin) * 1000 / CLOCKS_PER_SEC;
    }
    millis = somme / j;
    printf( "Temps moyen int * : %ld ms\n", millis );

    return 0;
}
