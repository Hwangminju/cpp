#include <iostream>

using namespace std;
void make_acc(int);
void add();
void sub();
void print_all();
void showMenu();

typedef struct
{
    int account_num;
    string name;
    int balance;
} Account;

Account account[100];
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
            make_acc(accNum++);
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
            print_all();
            break;
        case 5:
            return 0;
        }
    }
}

void showMenu()
{
    cout << endl;
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설\n2. 입 금\n3. 출 금\n4. 계좌정보 전체 출력\n5. 프로그램 종료" << endl;
}

void make_acc(int accNum)
{
    int i;
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> account[accNum].account_num;
    cout << "이 름: ";
    cin >> account[accNum].name;
    cout << "입금액: ";
    cin >> i;
    account[accNum].balance += i;
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
        if (id == account[idx].account_num)
            account[idx].balance += i;
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
        if (id == account[idx].account_num)
            account[idx].balance -= i;
    cout << "출금완료" << endl;
}

void print_all()
{
    int i=0;
    for (i=0; i<accNum; i++)
    {
        cout << "계좌ID: " << account[i].account_num << endl;
        cout << "이 름: " << account[i].name << endl;
        cout << "잔 액: " << account[i].balance << endl;
    }
}


