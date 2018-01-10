#include <iostream>
#include <cmath>
#include "Vector.h"

using namespace std;

/*class Vector() {
public:
    Vector(int s);
    double& operator[] (int i);
    int size();
private:
    double* elem;
    int sz;
};*/

double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i=0; i!=v.size(); ++i)
        sum += sqrt(v[i]);
    return sum;
}

Vector::Vector(int s) : elem{new double[s]}, sz{s} {}
double& Vector::operator[] (int i)
{
    return elem[i];
}

int Vector::size()
{
    return sz;
}

void Vector::put(int i, double a)
{
    elem[i] = a;
    cout << elem[i] << "\n";
}

int main()
{
    Vector v1 = Vector(3);
    v1.put(0,16);
    v1.put(1,9);
    v1.put(2,25);
    cout << sqrt_sum(v1) << "\n";
    return 0;
}
