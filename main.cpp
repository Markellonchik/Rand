#include "Generators.h"
#include <iostream>
#include <random>

using namespace std;

const int MIN_LEN = 10;
const int LEN = 100;
const int MOD = 1000000007;
const int A = 293;
const int C = 37436;
const int D = 32882;

Generator* create_generator(int type, int len = LEN){
    switch(type) {
    case 1:
        return new LinearGenerator(len, MOD, A, C);
    case 2:
        return new SquareGenerator(len, MOD, A, C, D);
    case 3:
        return new FibonacciGenerator(len, MOD);
    case 4:
        return new InverseGenerator(len, MOD, A, C);
    case 5:
        return new MergeGenerator(len, MOD);
    default:
        return new LinearGenerator(len, MOD, A, C);
    }
}

int poww(int a, int n){
    if(n == 0)return 1;
    int r = poww(a, n / 2);
    if(n & 1)return r * r * a;
    else return r * r;
}


int main()
{
    cout << "Choose your generator..." << endl;

    int type;
    while(cin >> type) {
        if(type <= 0)break;

        Generator *gen = create_generator(type, MIN_LEN);

        cout << "Sequence of " << MIN_LEN << " elements: " << endl;
        gen->generate();
        cout << *gen << endl;
        cout << gen->getGistagram() << endl;

        gen->setSize(LEN);

        cout << "Sequence of " << LEN << " elements" << endl;
        gen->generate();
        cout << gen->getGistagram() << endl;
        delete gen;
    }

    return 0;
}
