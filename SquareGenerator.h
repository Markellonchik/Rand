#include "UniformGenerator.h"
#ifndef SQUARE_GENERATOR
#define SQUARE_GENERATOR

class SquareGenerator : public UniformGenerator{
private:
    int A, C, D;
public:
    SquareGenerator(int len, int mod, int A, int C, int D);
    virtual void generate() override;
};

#endif //SQUARE_GENERATOR
