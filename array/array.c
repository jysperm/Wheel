#include <stdlib.h>
#include "array.h"

tArray* array_create(int elemSize, int length)
{
    void *data;
    tArray *array;

    data = malloc(elemSize * length);
    array = (tArray*) malloc(sizeof(tArray));

    array->elemSize = elemSize;
    array->length = length;
    array->data = data;

    return array;
}

tArray* array_create_defaults(int elemSize, int length, void *defaultValue)
{
     tArray *array;
     int iItem, iByte;

     array = array_create(elemSize, length);

     for(iItem = 0; iItem < length; iItem++)
        for(iByte = 0; iByte < elemSize; iByte++)
            ((char*) array->data)[iItem * elemSize + iByte] = ((char*) defaultValue)[iByte];

     return array;
}

tArray* array_copy(tArray *other)
{
    tArray *array;
    int iItem, iByte;

    array = array_create(other->elemSize, other->length);

    for(iItem = 0; iItem < other->length; iItem++)
        for(iByte = 0; iByte < other->elemSize; iByte++)
            ((char*) array->data)[iItem * other->elemSize + iByte] = ((char*) other->data)[iItem * other->elemSize + iByte];

    return array;
}

void array_override(tArray *target, tArray *source)
{

}

void array_free(tArray *array)
{
    free(array->data);
    free(array);
}

void* array_at(tArray *array, int offset)
{

}

void* array_frist(tArray *array)
{

}

void* array_last(tArray *array)
{

}

void* array_raw(tArray *array)
{
    return array->data;
}

int array_size(tArray *array)
{
    return array->length;
}

int array_elemSize(tArray *array)
{
    return array->elemSize;
}

int array_equal(tArray *a, tArray *b)
{

}

int array_not_equal(tArray *a, tArray *b)
{

}
