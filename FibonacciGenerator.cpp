#include "FibonacciGenerator.h"

FibonacciGenerator::FibonacciGenerator(int len, int mod) : UniformGenerator(len, mod), X1(mod / 4){
}

void FibonacciGenerator::generate(){
    if(size > 0)seq[0] = X0;
    if(size > 1)seq[1] = X1;
    for(int i = 2; i < size; ++i)
        seq[i] = ( seq[i - 1] + seq[i - 2] ) % mod;
}
