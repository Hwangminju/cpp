#include <iostream>
#include <cstring>

using namespace std;

void make_acc();
void add();
void sub();
void showMenu();
void showAllInfo();

class Account
{
private:
    int account_num;
    char* chName;
    int balance;
public:
    Account(int num, char* name, int money)
    : account_num(num), balance(money)
    {
        chName = new char[strlen(name)+1];
        strcpy(chName, name);
    }
    Account(){}
    ~Account(){delete []chName;}
    void add_(int money){balance += money;}
    void sub_(int money)
    {
        if (balance < money)
            return ;
        balance -= money;
    }
    void showInfo()
    {

        cout << "���¹�ȣ: " << account_num << endl;
        cout << "��  ��: " << chName << endl;
        cout << "��  ��: " << balance << endl;
    }
    int getAcc()
    {
        return account_num;
    }
};

Account * account[100];
int accNum = 0;

int main(void)
{
    while(true)
    {
        int i;
        showMenu();
        cout << "����: ";
        cin >> i;

        switch(i)
        {
        case 1:
            cout << endl;
            make_acc();
            break;
        case 2:
            cout << endl;
            add();
            break;
        case 3:
            cout << endl;
            sub();
            break;
        case 4:
            cout << endl;
            showAllInfo();
            break;
        case 5:
            for(int i=0; i<accNum; i++)
                delete account[i];
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
}

void showMenu()
{
    cout << endl;
    cout << "-----Menu-----" << endl;
    cout << "1.2.3.4.5...." << endl;
}

void make_acc()
{
    int a;
    char b[20];
    int c;
    cout << "[���°���]" << endl;
    cout << "����ID: "; cin >> a;
    cout << "�� ��: "; cin >> b;
    cout << "�Աݾ�: "; cin >> c;

    account[accNum++] = new Account(a,b,c);
}

void add()
{
    int id,i,idx;
    cout << "[��  ��]" << endl;
    cout << "����ID: ";
    cin >> id;
    cout << "�Աݾ�: ";
    cin >> i;
    for (idx=0; idx<accNum; idx++)
        if (id == account[idx]->getAcc()) account[idx]->add_(i);
    cout << "�ԱݿϷ�" << endl;
}

void sub()
{
    int id,i,idx;
    cout << "[��  ��]" << endl;
    cout << "����ID: ";
    cin >> id;
    cout << "��ݾ�: ";
    cin >> i;
    for (idx=0; idx<accNum; idx++)
        if (id == account[idx]->getAcc()) account[idx]->sub_(i);
    cout << "��ݿϷ�" << endl;
}

void showAllInfo()
{
    for (int i=0; i<accNum; i++)
    {
        account[i]->showInfo();
        cout << endl;
    }
}
