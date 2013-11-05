#include <iostream>
#include <cassert>
#include "array.h"

using namespace std;

int main()
{
    // construct
    Array<int> a(10, 0);
    Array<int> b = a;
        assert(b[5] == 0);
        assert(b.size() == 10);
    Array<int> *c = new Array<int>(5);
        assert(c->size() == 5);
    *c = a;
        assert(c->size() == 10);
    Array<string> d(3);

    // destructor
    delete c;

    // access
    a.at(0) = 1234;
        assert(a.frist() == 1234);
    a[8] = 4321;
        assert(a.at(8) == 4321);
        assert(a.last() == 0);
        assert(&a.frist() == a.raw());
    d.at(2) = "string";
        assert(d[2] == "string");

    // compare
    Array<int> e(10);
    e[0] = 1234;
    e[8] = 4321;
        assert((e == a) == true);
        assert((e != a) != true);
        assert((b == a) != true);

    cout<<"PASS array+"<<endl;

    return 0;
}
