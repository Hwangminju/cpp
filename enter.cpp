#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Slot
{
private:
    int i;
    int j;
    int k;
public:
    void start_slot();
};

void Slot::start_slot()
{
    while(1)
    {
        srand((unsigned)time(NULL));
        string c;
        getline(cin,c);
        if (c.empty())
        {
            i = rand()%10;
            cout << i;
        }
        getline(cin,c);
        if (c.empty())
        {
            j = rand()%10;
            cout << j;
        }
        getline(cin,c);
        if (c.empty())
        {
            k = rand()%10;
            cout << k;
        }

        if (i==7 && j==7 && k==7)
        {
            cout << "축하합니다!" << endl;
            return ;
        }
        if (j==i+1 && k==j+1)
            cout << "한번더!" << endl;
        cout << '\n' << "---" << endl;
    }
}

int main(void)
{
    Slot slot;
    slot.start_slot();
}
