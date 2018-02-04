#include <iostream>
#include <cstring>

using namespace std;

class Book
{
private:
    char *title;
    char *isbn;
    int price;
public:
    Book(char *t, char *i, int p) : price(p)
    {
        title = new char[strlen(t)+1];
        strcpy(title, t);
        isbn = new char[strlen(i)+1];
        strcpy(isbn, i);
    }
    void ShowBookInfo()
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
};

class EBook : public Book
{
private:
    char *DRMKey;
public:
    EBook(char *t, char *i, int p, char* D) : Book(t,i,p)
    {
        DRMKey = new char[strlen(D)+1];
        strcpy(DRMKey, D);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }
};

int main(void)
{
    Book book("C++","555",20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("ebook","555",10000,"fd");
    ebook.ShowEBookInfo();
    return 0;
}
