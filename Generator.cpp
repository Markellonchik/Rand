#include "Generator.h"
#include <iostream>

void Generator::setSize(int len){
    int *newSeq = new int[len];
    for(int i = 0; i < len; ++i)newSeq[i] = 0;
    delete []seq;
    seq = newSeq;
    size = len;
}

Generator::Generator(int len) : size(len), seq(new int[len]) {
    for(int i = 0; i < len; ++i)seq[i] = 0;
}

int Generator::operator [] (int n) const{
    return seq[n];
}

std::ostream& operator << (std::ostream& out, const Generator &o) {
    out << "Sequense length = " << o.size << "\n";
    out << "Sequense: [";
    for(int i = 0; i < o.size; ++i) {
        if(i)out << ", ";
        out << o[i];
    }
    out << "]";
    return out;
}
Generator::~Generator() {
    delete[] seq;
}
