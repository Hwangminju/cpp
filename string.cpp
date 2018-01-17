#include <iostream>
#include <cstring>

using namespace std;

class Printer
{
private:
    char str[20];
public:
    void SetString(char* s)
    {
        strcpy(str, s);
    }
    void ShowString()
    {
        cout << str << endl;
    }
};

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}
