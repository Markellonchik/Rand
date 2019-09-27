#include "UniformGenerator.h"
#ifndef INVERSE_GENERATOR
#define INVERSE_GENERATOR

class InverseGenerator : public UniformGenerator{
private:
    int A, C, modPhi;
    void gcd(int a, int b, int &x, int &y);
    int phi(int n);
    int modPow(int a, int p, int mod);
    int modularInverse_alg1(int a, int mod);
    int modularInverse_alg2(int a, int mod);
    int modularInverse(int a, int mod);
public:
    InverseGenerator(int len, int mod, int A, int C);
    void generate();
};

#endif // INVERSE_GENERATOR
