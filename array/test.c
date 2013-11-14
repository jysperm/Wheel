#include <stdio.h>
#include <assert.h>
#include "array.h"

int main()
{
    tArray *a, *b, *c, *d, *e;
    int default0 = 0;
    const char* string = "string";

    // construct
    a = array_create_defaults(sizeof(int), 10, (void*)&default0);
    b = array_copy(a);
        assert(*((int*)array_at(b, 5)) == 0);
        assert(array_size(b) == 10);
    c = array_create(sizeof(int), 5);
        assert(array_size(c) == 5);
    array_override(c, a);
        assert(array_size(c) == 10);
    d = array_create(sizeof(const char*), 3);

    // destructor
    array_free(c);

    // access
    *((int*)array_at(a, 0)) = 1234;
        assert(*((int*)array_frist(a)) == 1234);
    *((int*)array_at(a, 8)) = 4321;
        assert(*((int*)array_at(a, 8)) == 4321);
        assert(*((int*)array_last(a)) == 0);
        assert(array_frist(a) == array_raw(a));
    *((const char**)array_at(d, 2)) = string;
        assert(*((const char**)array_at(d, 2)) == string);

    // compare
    e = array_create(sizeof(int), 10);
    *((int*)array_at(e, 0)) = 1234;
    *((int*)array_at(e, 8)) = 4321;
        assert(array_equal(e, a) == 1);
        assert(array_not_equal(e, a) != 1);
        assert(array_equal(b, a) != 1);


    printf("PASS array\n");
    return 0;
}

