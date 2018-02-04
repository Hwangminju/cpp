#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}
    friend ostream& operator << (ostream&, const Point&);
    friend istream& operator >> (istream&, Point&);
};

ostream& operator << (ostream& os, const Point& p)
{
    os << '[' << p.xpos << ", " << p.ypos << ']' << endl;
    return os;
}

istream& operator >> (istream& is, Point& p)
{
    is >> p.xpos >> p.ypos;
    return is;
}

int main(void)
{
    Point pos1;
    cout << "x,y 좌표 순으로 입력: ";
    cin >> pos1;
    cout << pos1;

    return 0;
}
