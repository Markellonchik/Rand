#include "UniformGenerator.h"
#include "LinearGenerator.h"
#include "InverseGenerator.h"

#include "InverseGenerator.h"

#ifndef MERGE_GENERATOR
#define MERGE_GENERATOR


class MergeGenerator : public UniformGenerator {
private:
    Generator *gen1, *gen2;
    const int A = 3192;
    const int B = 9281;
public:
    virtual ~MergeGenerator() override;
    MergeGenerator(int len, int mod);
    virtual void generate() override;
    virtual void setSize(int len) override;
};

#endif // MERGE_GENERATOR
