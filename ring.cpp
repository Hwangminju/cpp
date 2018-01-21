#include <iostream>

using namespace std;

class Point
{
private:
    int xpos,ypos;
public:
    void Init(int x,int y)
    {
        xpos=x;
        ypos=y;
    }
    void ShowPointInfo() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle
{
private:
    Point p;
    int radius;
public:
    void Init(int x,int y, int r)
    {
        p.Init(x,y);
        radius = r;
    }

    void ShowCircleInfo() const
    {
        cout << "radius: " << radius << endl;
        p.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle inner;
    Circle outer;
public:
    void Init(int i_x,int i_y,int i_r,int o_x,int o_y,int o_r)
    {
        inner.Init(i_x,i_y,i_r);
        outer.Init(o_x,o_y,o_r);
    }
    void ShowRingInfo()
    {
        cout << "Inner Circle Info..." << endl;
        inner.ShowCircleInfo();

        cout << "Outer Circle Info..." << endl;
        outer.ShowCircleInfo();
    }
};

int main(void)
{
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}
