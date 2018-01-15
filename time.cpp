#include <iostream>
#include <ctime>
#include <chrono>
#include <ratio>

using namespace std;
using namespace std::chrono;

void do_work() {
    for (int a=0;a<30;++a)
        cout << "yeah" << endl;
}

int main() {
    auto t0 = chrono::high_resolution_clock::now();
    do_work();
    auto t1 = chrono::high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t1-t0).count() << "msec\n";
}
