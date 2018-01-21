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

        cout << "계좌번호: " << account_num << endl;
        cout << "이  름: " << chName << endl;
        cout << "잔  액: " << balance << endl;
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
        cout << "선택: ";
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
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: "; cin >> a;
    cout << "이 름: "; cin >> b;
    cout << "입금액: "; cin >> c;

    account[accNum++] = new Account(a,b,c);
}

void add()
{
    int id,i,idx;
    cout << "[입  금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "입금액: ";
    cin >> i;
    for (idx=0; idx<accNum; idx++)
        if (id == account[idx]->getAcc()) account[idx]->add_(i);
    cout << "입금완료" << endl;
}

void sub()
{
    int id,i,idx;
    cout << "[출  금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "출금액: ";
    cin >> i;
    for (idx=0; idx<accNum; idx++)
        if (id == account[idx]->getAcc()) account[idx]->sub_(i);
    cout << "출금완료" << endl;
}

void showAllInfo()
{
    for (int i=0; i<accNum; i++)
    {
        account[i]->showInfo();
        cout << endl;
    }
}
