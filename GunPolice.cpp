#include <iostream>
#include <cstring>

using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum) {}
    void Shut()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;
    Gun *pistol;
public:
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        if(bnum>0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void Shut()
    {
        if(pistol==NULL)
            cout << "Hut BBANG!" << endl;
        else
            pistol->Shut();
    }
    ~Police()
    {
        if(pistol!=NULL)
            delete pistol;
    }
    Police(const Police& ref) : handcuffs(ref.handcuffs)
    {
        pistol = new pistol(*(ref.pistol));
    }
    // 깊은 복사 생성자
    Police& operator=(const Police& ref)
    {
        if(pistol!=NULL)
            delete pistol;
        handcuffs = ref.handcuffs;
        pistol = new Gun(*(ref.pistol)); // 복사생성자
        return *this;
    }
};

int main(void)
{
    Police p1(3,5);
    Police p2 = p1; // 복사 생성자
    p2.Shut();

    Police p3(1,1);
    p3 = p1; // 대입 연산자
    p3.Shut();
}
