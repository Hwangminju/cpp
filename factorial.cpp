#include <iostream>

using namespace std;

template<int N>
struct Factorial
{
    static const int result = N * Factorial<N-1>::result;
};

template<>
struct Factorial<1>
{
    static const int result = 1;
};

int main()
{
    cout << "3! = " << Factorial<3>::result << endl;
}
