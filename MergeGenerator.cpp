#include "MergeGenerator.h"

MergeGenerator::~MergeGenerator() {
    delete gen1;
    delete gen2;
}

MergeGenerator::MergeGenerator(int len, int mod) : UniformGenerator(len, mod){
    gen1 = new InverseGenerator(len, mod, A, B);
    gen2 = new LinearGenerator(len, mod - 2, A - 1, B + 1);
}

void MergeGenerator::setSize(int len) {
    UniformGenerator::setSize(len);
    gen1->setSize(len);
    gen2->setSize(len);
}

void MergeGenerator::generate() {
    gen1->generate();
    gen2->generate();

    for(int i = 0; i < size; ++i) {
        seq[i] = (*gen1)[i] - (*gen2)[i];
        if(seq[i] < 0)seq[i] += mod;
    }
}


