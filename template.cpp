#include <iostream>

using namespace std;

// 함수 템플릿
template<typename T>
void Swap(T& num1, T& num2)
{
    T temp = num1;
    num1 = num2;
    num2 = temp;
}

// 클래스 템플릿
template<typename T>
class Data
{
private:
    T data;
public:
    Data(T data) : data(data) {}
    void ShowInfo()
    {
        cout << data << endl;
    }
};

int main()
{
    cout << "=======function template=======" << endl;
    int num1=10, num2=40;
    cout << "before, num1: " << num1 << ", num2: " << num2 << endl;
    Swap(num1,num2);
    cout << "after, num1: " << num1 << ", num2: " << num2 << endl;

    double num3=15.6, num4=14.44;
    cout << "before, num3: " << num3 << ", num4: " << num4 << endl;
    Swap(num3,num4);
    cout << "after, num3: " << num3 << ", num4: " << num4 << endl;

    cout << endl << endl;
    cout << "=======class template=======" << endl;
    Data<int> data1(50);
    data1.ShowInfo();

    Data<char> data2('A');
    data2.ShowInfo();

    Data<double> data3(24.377);
    data3.ShowInfo();
        return 0;
}
