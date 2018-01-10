#include <iostream>
#include <type_traits>

using namespace std;

enum class Color { red, blue, green };
enum class Traffic_light { green = 3, yellow, red };

Color col = Color::red;
Traffic_light light = Traffic_light::red;

Traffic_light& operator++ (Traffic_light& t)
{
    switch (t) {
    case Traffic_light::green:
        return t = Traffic_light::yellow;
    case Traffic_light::yellow:
        return t = Traffic_light::red;
    case Traffic_light::red:
        return t = Traffic_light::green;
    }
}

std::ostream& operator << (std::ostream& os, const Traffic_light& obj)
{
   os << static_cast<std::underlying_type<Traffic_light>::type>(obj);
   return os;
}

int main()
{
    Traffic_light next = ++light; //위에서 정의한 operator 사용
    cout << next << "\n";
    return 0;
}
