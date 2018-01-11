#include <iostream>
#include <stdexcept>
#include <list>

using namespace std;

template<typename T>
class Vector {
private:
    T* elem;
    int sz;
public:
    Vector(int s);
    ~Vector() {delete[] elem;}
    T& operator[] (int i);
    const T& operator[] (int i) const;
    int size() const {return sz;}
    T* begin();
    T* end();
};

class Negative_size : public std::exception {
};

template<typename T>
Vector<T>::Vector(int s)
{
    if (s<0) throw Negative_size{};
    elem = new T[s];
    sz = s;
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
    if (i<0 || size() <=i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

template<typename T>
T& Vector<T>::operator[] (int i)
{
    if (i<0 || size() <=i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

template<typename T>
T* begin(Vector<T>& x)
{
    return x.size()? &x[0]: nullptr; // size가 1이면 원소 그대로 출력하고 아니면 nullptr 출력
}

template<typename T>
T* end(Vector<T>& x)
{
    return begin(x)+x.size();
}

void write(const Vector<string>& vs)
{
    for (int i=0; i!=vs.size(); ++i)
        cout << vs[i] << '\n';
}

void f2(Vector<string>& vs)
{
    for (auto& s : vs)
        cout << s << '\n';
}

template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
    for (auto x : c) {
        v += x;
    }
    return v;
}

template<typename T>
class Less_than {
    const T val;
public:
    Less_than(const T& v) : val(v) {}
    bool operator()(const T& x) const {return x<val;}
};

Less_than<int> lti {42};
Less_than<string> lts {"Backus"};

template<typename C, typename P>
int count(const C& c, P pred)
{
    int cnt = 0;
    for (const auto& x : c)
        if (pred(x))
            ++cnt;
    return cnt;
}

template<typename C, typename oper>
void for_all(C& c, Oper op)
{
    for (auto& x : c)
        op(*x);
}

void user()
{
    vector<unique_ptr<Shape>> v;
    while(cin)
        v.push_back(read_shape(cin));
    for_all(v,[](Shape& s) {s.draw(); });
    for_all(v,[](Shape& s) {s.rotate(); });
}

void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
    cout << "number of values less than " << x
    << ": " << count(vec, Less_than<int>{x})
    << '\n';
    cout << "number of values less than " << s
    << ": " << count(lst, Less_than<string>{s})
    << '\n';
}

void user(Vector<int>& vi, std::list<double>& ld, std::vector<complex<double>>& vc)
{
    int x = sum(vi,0);
    double d = sum(vi,0.0);
    double dd = sum(ld,0.0);
    auto z = sum(vc, complex<double>{})
}

void fct(int n, const string& s)
{
    bool b1 = lti(n); // n<42이면 true
    bool b2 = lts(s); // s<"Backus"이면 true
}

int main()
{
    Vector<int> v(10);
    Vector<char> vc(200);
    Vector<string> vs(17);
    Vector<list<int>> vli(45);
}
