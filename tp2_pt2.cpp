#include<iostream> 
#include<ctime> 
#include <math.h>
#include <stdio.h>

// Déplacez la définition de la fonction u en dehors de main()
double u(double sig, double eps, double r) {
    return 4 * eps * (pow(sig, 12) / pow(r, 12) - pow(sig, 6) / pow(r, 6));
}

double u_fast1(double sig, double eps, double r) {
    double sig3 = sig * sig * sig;
    double sig6 = sig3 * sig3;
    double r3 = r * r * r;
    double r6 = r3 * r3;
    return 4 * eps * ((sig6 * sig6) * (1 / (r6 * r6)) - (sig6 * (1 / r6)));
}




main() {
    double x = 0;
    std::clock_t start_time_multi = std::clock();
    double eps=1;
    double sig=2;
    double r=3;
    double eps4=eps*4;
    double sig3=sig*sig*sig;
    double sig6=sig3*sig3;
    double sig12 = sig6*sig6;
    

    for (long int i = 0; i < 1e9; i++) {
        x = u_fast1(1, 2, 3);
        //x = u(1,2,3); 
        //double r3 = r * r * r;
        //double r6 = r3 * r3;
        //x = eps4 * ((sig12 / (r6*r6)) - (sig6  / r6));
    }
    std::clock_t end_time_multi = std::clock();
    double temps_multi = (end_time_multi - start_time_multi) / (double)CLOCKS_PER_SEC;
    std::cout << "temps : " << temps_multi << std::endl;
}
