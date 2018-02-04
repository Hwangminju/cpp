#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo
{
private:
    char *name;
    int age;
public:
    MyFriendInfo(char *myname, int myage) : age(myage)
    {
        cout << "MyFriendInfo()" << endl;
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
    }
    ~MyFriendInfo()
    {
        cout << "~MyFriendInfo()" << endl;
        delete []name;
    }
    void ShowMyFriendInfo()
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char *addr;
    char *phone;
public:
    MyFriendDetailInfo(char* myname, int myage, char *myaddr, char *myphone) : MyFriendInfo(myname, myage)
    {
        cout << "MyFriendDetailInfo()" << endl;
        addr = new char[strlen(myaddr)+1];
        strcpy(addr, myaddr);
        phone = new char[strlen(myphone)+1];
        strcpy(phone, myphone);
    }
    ~MyFriendDetailInfo()
    {
        cout << "~MyFriendDetailInfo()" << endl;
        delete []addr;
        delete []phone;
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "주소 : " << addr << endl;
        cout << "전화 : " << phone << endl << endl;
    }
};

int main(void)
{
    MyFriendDetailInfo m1("황",22,"강남","010");
    m1.ShowMyFriendDetailInfo();
}
