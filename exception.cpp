#include <iostream>
#include "Vector.h"
#include <stdexcept>

using namespace std;

Vector::Vector(int s) : elem{new double[s]}, sz{s} {}

double& Vector::operator[](int i)
{
    if (i<0 || size() <= i) throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

int Vector::size()
{
    return sz;
}

void f(Vector& v)
{
    try {
        v[v.size()] = 7;
    }
    catch (out_of_range) {
        cout <<"Error" << "\n";
    }
}

int main()
{
    Vector v1(4);
    f(v1);
    return 0;
}
