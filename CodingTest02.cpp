#include <iostream>

using namespace std;

int N,B,C;
int A[1000000];
int super = 0;

int getSuper();

int main()
{
    cin >> N;

    for (int i=0; i<N; i++)
        cin >> A[i];
    cin >> B >> C;

    cout << getSuper();
}

int getSuper()
{
    for(int i=0; i<N; i++)
    {
        super += 1;
        int rest = A[i] - B;
        while(rest > 0)
        {
            rest = rest-C;
            super += 1;
        }
    }
    return super;
}
