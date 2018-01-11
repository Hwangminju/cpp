#include <iostream>
#include <cstddef>

using namespace std;
using size_t = unsigned int;

template<typename T>
class Vector {
public:
        using value_type = T;
};

template<typename C>
using Value_type = typename C::value_type;

template<typename Container>
void algo(Container& c)
{
    Vector<Value_type<Container>> vec;
}

template<typename Key, typename Value>
class Map {

};

template<typename Value>
using String_map = Map<string, int>;
String_map<int> m;
