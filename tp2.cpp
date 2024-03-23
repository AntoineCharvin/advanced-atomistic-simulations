#include<iostream> 
#include<ctime> 
#include <math.h>
#include <stdio.h>

main() {
 double x=0;
 std::clock_t start_time_multi = std::clock();
 for (long int i; i<1000; i++) {
 x += sinh(x);
 }
 std::clock_t end_time_multi = std::clock();
 double temps_multi = (end_time_multi - start_time_multi)/(double)CLOCKS_PER_SEC;
 std::cout<<"temps de la multiplication reel "<<temps_multi<<std::endl;
}


