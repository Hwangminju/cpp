/*#include <iostream>

using namespace std;

Vector operator+(const Vector& a, const Vector& b)
{
    if (a.size()!=b.size())
        throw Vector_size_mismatch{};
    Vector res(a.size());
    for (int i=0; i!=a.size(); ++i)
        res[i] = a[i]+b[i];
    return res;
}

void f(const Vector& x, const Vector& y, const Vector& z)
{
    Vector r;
    r = x+y+z;
}

class Vector {
    Vector(const Vector& a);
    Vector& operator=(const Vector& a);
    Vector(const Vector&& a);
    Vector& operator=(const Vector&& a);
};*/

#include <iostream>
#include <vector>

using namespace std;

class Test{
public:
    char *data;
    char name;
    int id;

    Test(char _name)
    {
        data = new char[1000000];
        id = cnt++;
        name = _name;

        cout << "id : " << id << " 생성자 호출 - 메모리의 주소 : " << (void*)data << endl;
        cout << "name : " << name << endl;
    }

    Test(const Test &other)
    {
        data = new char[1000000];
        memcpy(data, other.data, 1000000);
        id = cnt++;
        name = other.name;

        cout << "id : " << id << " 복사생성자 - 메모리의 주소 : " << (void*)data << endl;
        cout << "name : " << name << endl;
    }

    Test(Test &&other)
    {
        id = other.id;
        data = other.data;
        other.data = nullptr;
        cout << "id : " << id << " 이동생성자 - 메모리의 주소 : " << (void*)data << endl;
    }

    Test& operator=(const Test &other)
    {
        if (this==&other)
            return *this;
        delete[] data;
        data = new char[1000000];
        memcpy(data, other.data, 1000000);
        name = other.name;

        cout << "id : " << id << " 할당연산자 - 메모리의 주소 :" << (void*)data << endl;
        cout << "name : " << name << endl;

        return *this;
    }

    ~Test()
    {
        cout << "id : " << id << " 소멸자 호출 - 메모리의 주소 : " << (void*)data << endl;
        cout << "name : " << name << endl;
        delete[] data;
    }

    static int cnt;
};

int Test::cnt = 1;

int main()
{
    Test a{'a'};
    cout << "---------------------------------------------------------" << endl;

    Test b{'b'};
    cout << "---------------------------------------------------------" << endl;

    std::vector<Test> vec;

    vec.push_back(std::move(a));
    cout << "---------------------------------------------------------" << endl;

    vec.push_back(std::move(b));
    cout << "---------------------------------------------------------" << endl;
}

