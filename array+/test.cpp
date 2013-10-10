#include <iostream>
#include <cassert>
#include "array.h"

using namespace std;

int main()
{
    Array<int> a(10, 0);
    
    a.at[0] = 1234;
    a.at[8] = 1234;
    assert(a[0] == 1234);
    assert(a.last() == 0);
    
    Array<int> b = a;
    
    assert(b.size() == 10);
    b[8] = 4321;
    
    assert(a[8] == 1234);
    assert(&b.frist() == b.raw());
}
