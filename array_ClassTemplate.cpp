#include <iostream>
#include <cstring>

using namespace std;

template<typename T>
class Array
{
private:
    T* buf;
    int size;
    int capacity;
public:
    explicit Array(int cap=100)
    : buf(0),size(0),capacity(cap)
    {
        buf = new T[capacity];
    }
    ~Array() {delete []buf;}
    void Add(T data)
    {
        buf[size++] = data;
    }
    T operator[] (int idx) const
    {
        return buf[idx];
    }
    int GetSize() const
    {
        return size;
    }
};

int main()
{
    Array<int> arr;

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);

    for (int i=0;i<arr.GetSize();i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    Array<double> darr;
    darr.Add(10.12);
    darr.Add(20.12);
    darr.Add(30.12);

    for (int i=0;i<darr.GetSize();i++)
    {
        cout << darr[i] << " ";
    }
    cout << endl;

    Array<string> sarr;
    sarr.Add("abc");
    sarr.Add("ABC";
    sarr.Add("Hello");

    for (int i=0;i<sarr.GetSize();i++)
    {
        cout << sarr[i] << " ";
    }
    cout << endl;

    return 0;
}
