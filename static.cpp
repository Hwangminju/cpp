#include <iostream>

using namespace std;

class Date
{
    int d,m,y;
    static Date default_date;
public:
    Date(int dd=0,int mm=0,int yy==0);
    static void set_default(int dd,int mm,int yy);
};

Date::Date(int dd,int mm,int yy)
{
    d=dd?dd:default_date.d;
    m=mm?mm:default_date.m;
    y=yy?yy:default_date.y;
}

void f()
{
    Date::set_default(4,5,1945);
}

Date Date::default_date{16,12,1770};

void Date::set_default(int d,int m,int y)
{
    default_date={d,m,y};
}

Date copy_of_default_date = Date{};

void f(Date);
void g()
{
    f({});
    f(Date{});
}
