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
        cout << "����: ";
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
    cout << "1. ���°���\n2. �� ��\n3. �� ��\n4. �������� ��ü ���\n5. ���α׷� ����" << endl;
}

void make_acc(int accNum)
{
    int i;
    cout << "[���°���]" << endl;
    cout << "����ID: ";
    cin >> account[accNum].account_num;
    cout << "�� ��: ";
    cin >> account[accNum].name;
    cout << "�Աݾ�: ";
    cin >> i;
    account[accNum].balance += i;
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
        if (id == account[idx].account_num)
            account[idx].balance += i;
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
        if (id == account[idx].account_num)
            account[idx].balance -= i;
    cout << "��ݿϷ�" << endl;
}

void print_all()
{
    int i=0;
    for (i=0; i<accNum; i++)
    {
        cout << "����ID: " << account[i].account_num << endl;
        cout << "�� ��: " << account[i].name << endl;
        cout << "�� ��: " << account[i].balance << endl;
    }
}


