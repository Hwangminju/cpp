#include <iostream>

using namespace std;

class Calculator
{
private:
    int addCount = 0;
    int minCount = 0;
    int mulCount = 0;
    int divCount = 0;
public:
    double Add(double a, double b);
    double Div(double a, double b)
    {
        divCount++;
        return a/b;
    };
    double Min(double a, double b)
    {
        minCount++;
        return a-b;
    };
    void Init()
    {
        a = 0;
        b = 0;
    }
    void ShowOpCount()
    {
        cout << "µ¡¼À: " << addCount << " »¬¼À: " << minCount << " °ö¼À: " << mulCount << " ³ª´°¼À: " << divCount << endl;
    }
};

double Calculator::Add(double a, double b)
{
    addCount++;
    return a+b;
}

int main(void)
{
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2,2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5,1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2,1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9,1.2) << endl;
    cal.ShowOpCount();
    return 0;
}
