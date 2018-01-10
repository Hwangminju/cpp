#include <iostream>

using namespace std;

class Vector {
private:
    double* elem;
    int sz;
public:
    Vector(int n);
    ~Vector() { delete[] elem; }
    Vector(const Vector& a);
    Vector& operator=(const Vector& a);
    double& operator[] (int i);
    const double& operator[] (int i) const;
    int size() const;
    void put(int, double);
};

Vector::Vector(int s) : elem{new double[s]}, sz{s} {}

Vector::Vector(const Vector& a) : elem{new double[a.sz]}, sz{a.sz}
{
    for (int i=0; i!=sz; ++i)
        elem[i] = a.elem[i];
}

Vector& Vector::operator=(const Vector& a)
{
    double* p = new double[a.sz];
    for (int i=0; i!=a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}

double& Vector::operator[] (int i)
{
    return elem[i];
}

int Vector::size() const
{
    return sz;
}

void copy_vec(Vector v1)
{
    Vector v2(3);
    v2 = v1;
    for(int i=0; i!=v2.size(); ++i)
        cout << v2[i] << " ";
    cout << "\n";
}

void Vector::put(int i, double a)
{
    elem[i] = a;
}

int main()
{
    Vector v1(3);
    v1.put(0,5);
    v1.put(1,7);
    v1.put(2,3);

    copy_vec(v1);
}
