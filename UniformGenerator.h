#ifndef EVEN_GENERATOR
#define EVEN_GENERATOR

#include "Generator.h"
#include <iostream>
#include <string>

class UniformGenerator : public Generator{
protected:
    int mod;
    int X0;
public:
    UniformGenerator(int len, int mod);
    std::string getGistagram();
};
#endif // EVEN_GENERATOR
