#include "SquareGenerator.h"

SquareGenerator::SquareGenerator(int len, int mod, int A, int C, int D) :
                                UniformGenerator(len, mod), A(A), C(C), D(D){
}

void SquareGenerator::generate() {
    if(size > 0) seq[0] = X0;
    for(int i = 1; i < size; ++i) {
        int DX = ( ( seq[i - 1] * 1ll * seq[i - 1] ) % mod ) * D % mod;
        seq[i] = ( DX + seq[i - 1] * 1ll * A + C ) % mod;
    }
}
