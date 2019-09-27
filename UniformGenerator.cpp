#include "UniformGenerator.h"
#include <sstream>

UniformGenerator::UniformGenerator(int len, int mod) : Generator(len), mod(mod), X0(mod / 2){
}

std::string UniformGenerator::getGistagram() {
    std::ostringstream gist;

    gist << std::fixed;
    gist.precision(3);

    gist << "Interval\tChastota\n";
    double ch[10];
    for(int i = 0; i < 10; ++i)ch[i] = 0;
    for(int i = 0; i < size; ++i) {
        double x = double(seq[i]) / mod;
        ch[int(x * 10)]++;
    }

    for(int i = 0; i < 10; ++i) {
        gist << "[0";
        if(i)gist << "." << i;
        gist << "; ";

        if(i < 9)gist << "0." << i + 1 << "]";
        else gist << "1.0]";
        gist << "\t" << ch[i] / size << "\n";
    }
    return gist.str();
}
