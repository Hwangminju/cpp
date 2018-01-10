#include <iostream>

using namespace std;

class Vector {
private:
    double *elem;
    int sz;
public:
    Vector(int s) : elem{new double[s]}, sz{s}
    {
        for (int i=0; i!=s; ++i) elem[i] = 0;
    }
    ~Vector() { delete[] elem; }

    double& operator[] (int i);
    int size() const;
    Vector(std::initializer_list<double>);
    void push_back(double);
};

double& Vector::operator[] (int i)
{
    return elem[i];
}

int Vector::size() const
{
    return sz;
}

Vector::Vector(std::initializer_list<double> lst) :elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
{
    copy(lst.begin(), lst.end(), elem); // lst에서 elem으로 복사
}

void fct(int n)
{
    Vector v(n);
    {
        Vector v2(2*n);
    } // v2는 여기서 소멸된다.
} // v는 여기서 소멸된다.

int main()
{
    Vector v1 = {1,2,3,4,5};
    Vector v2 = {1.23,3.45,6.7,8};

    for(int i=0; i!=v1.size(); ++i)
        cout << v1[i] << "\n";
}
