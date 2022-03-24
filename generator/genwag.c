#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"

double genwag(double min, double max){
    srand(time(NULL));

    return ((max - min)*((double)rand() / RAND_MAX)) + min; 
    //generuje wagi w zakresie od min do max liczby
}