#include <iostream>

using namespace std;

void print() {
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    for (auto x : v)�� // v�� ���Ҹ� x�� ���������� ����
        cout << x << "\n";
    for (auto x : {10,21,32,43,54,65})
        cout << x << "\n";
}

void increment() {
    int v[] = {0,5,2,7,4,3,6,9,11,2};
    for (auto& x : v) { // v�� ���Ҹ� �������� �ʰ� ������
        ++x;
        cout << x << "\n";
    }
}

int count_x (char* p, char x) {
    if (p == nullptr) return 0;
    int count = 0;
    for (; *p!=0; ++p)
        if (*p == x)
        ++count;
}

int main() {
    print();
    cout << "\n";
    increment();
}
