#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

class Vector {
public:
    Vector(int s);
    double& operator[] (int i);
    int size();
    void put(int i, double a);
private:
    double* elem;
    int sz;
};

#endif // VECTOR_H_INCLUDED
