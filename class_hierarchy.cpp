#include <iostream>

using namespace std;

class Shape {
public:
    virtual Point center() const = 0;
    virtual void move(Point to) = 0;
    virtual void draw() const = 0;
    virtual void rotate(int angle) = 0;
    virtual ~Shape() {}
};

void rotate_all(vector<Shape*> &v, int angle)
{
    for (auto p : v)
        p->rotate(angle);
}

class Circle : public Shape {
private:
    Point x;
    int r;
public:
    Circle(Point p, int rr);
    Point center() const { return x; }
    void move(Point to) { x = to; }
    void draw() const;
    void rotate(int) {}
};

class Smiley : public Circle {
private:
    vector<Shape*> eyes;
    Shape* mouth;
public:
    Smiley(Point p, int r} : Circle(p,r), mouth{nullptr};
    ~Smiley()
    {
        delete mouth;
        for (auto p : eyes) delete p;
    }

    void move(Point to);
    void draw() const;
    void rotate(int);
    void add_eye(Shape* s) { eyes.push_back(s); }
    void set_mouth(Shape* s);
    virtual void wink(int i);
};

void Smiley::draw()
{
    Circle::draw();
    for(auto p : eyes)
        p->draw();
    mouth->draw();
}

enum class Kind { circle, triangle, smiley };
Shape* read_shape (istream& is)
{
    switch (k) {
    case Kind::circle:
        return new Circle{p,r};
    case Kind::triangle:
        return new Triangle{p1,p2,p3};
    case Kind::smiley:
        Smiley* ps = new Smiley{p,r};
        ps->add_eye(e1);
        ps->add_eye(e2);
        ps->set_mouth(m);
        return ps;
    }
}

void user()
{
    std::vector<Shape*> v;
    while(cin)
        v.push_back(read_shape(cin));
    draw_all(v);
    rotate_all(v,45);
    for (auto p : v) delete p;
}

int main()
{
    user();
}
