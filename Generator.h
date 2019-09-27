#include<iostream>
#include<string>
#ifndef MAIN_GENERATOR
#define MAIN_GENERATOR
class Generator{
private:
protected:
    int size;
    int *seq;
public:
    virtual void setSize(int);
    Generator(int);
    int operator[] (int n) const;
    virtual void generate()=0;
    virtual std::string getGistagram() = 0;
    virtual ~Generator();
    friend std::ostream& operator << (std::ostream &buf,const Generator& o);
};
#endif // MAIN_GENERATOR
