#include "InverseGenerator.h"
#include <cstdlib>

void InverseGenerator::gcd(int a, int b, int &x, int &y) {
    if(a == 0) {
        x = 0;
        y = 1;
    }else{
        int x1, y1;
        gcd(b % a, a, x1, y1);
        x = y1 - x1 * (b / a);
        y = x1;
    }
}

int InverseGenerator::phi(int n) {
    int res = n;
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0){
            while(n % i == 0)n /= i;
            res -= res / i;
        }
    }
    if(n > 1)res -= res / n;
    return res;
}

int InverseGenerator::modPow(int a, int pow, int mod) {
    int res = 1;
    while(pow){
        if(pow & 1)res = res * 1ll * a % mod;
        a = a * 1ll * a % mod;
        pow /= 2;
    }
    return res;
}

int InverseGenerator::modularInverse_alg1(int a, int mod) {
    int x, y;
    gcd(a, mod, x, y);
    if(x < 0)x += mod;
    return x;
}

int InverseGenerator::modularInverse_alg2(int a, int mod) {
    return modPow(a, modPhi - 1, mod);
}

int InverseGenerator::modularInverse(int a, int mod) {
    int res = modularInverse_alg1(a, mod);
    if(res * 1ll * a % mod != 1)exit(1);
    return res;
}

void InverseGenerator::generate() {
    if(size > 0) seq[0] = X0;
    for(int i = 1; i < size; ++i) {
        seq[i] = ( modularInverse(seq[i - 1], mod) * 1ll * A + C ) % mod;
    }
}

InverseGenerator::InverseGenerator(int len, int mod, int A, int C)
                                : UniformGenerator(len, mod), A(A), C(C){
    modPhi = phi(mod);
}
