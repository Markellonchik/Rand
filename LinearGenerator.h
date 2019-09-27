#include "SquareGenerator.h"
#ifndef LINEAR_GENERATOR
#define LINEAR_GENERATOR

class LinearGenerator : public SquareGenerator{
public:
    LinearGenerator(int len, int mod, int A, int C);
};

#endif // LinearGenerator
