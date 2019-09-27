#include "UniformGenerator.h"
#ifndef FIBONACCI_GENERATOR
#define FIBONACCI_GENERATOR

class FibonacciGenerator : public UniformGenerator {
private:
    int X1;
public:
    FibonacciGenerator(int len, int mod);
    virtual void generate() override;
};

#endif //FIBONACCI_GENERATOR
