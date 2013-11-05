#include <stdlib.h>
#include "array.h"

sArray* array_create(int elemSize, int length)
{
    void *data;
    sArray *array;

    data = malloc(elemSize * length);
    array = (sArray*) malloc(sizeof(sArray));

    array->elemSize = elemSize;
    array->length = length;
    array->data = data;

    return array;
}

sArray* array_create_defaults(int elemSize, int length, void *defaultValue)
{
     sArray *array;
     int iItem, iByte;

     array = array_create(elemSize, length);

     for(iItem = 0; iItem < length; iItem++)
        for(iByte = 0; iByte < elemSize; iByte++)
            ((char*) array->data)[iItem * elemSize + iByte] = ((char*) defaultValue)[iByte];

     return array;
}

sArray* array_copy(sArray *other)
{
    sArray *array;
    int iItem, iByte;

    array = array_create(other->elemSize, other->length);

    for(iItem = 0; iItem < other->length; iItem++)
        for(iByte = 0; iByte < other->elemSize; iByte++)
            ((char*) array->data)[iItem * other->elemSize + iByte] = ((char*) other->data)[iItem * other->elemSize + iByte];

    return array;
}

void array_override(sArray *target, sArray *source)
{

}

void array_free(sArray *array)
{
    free(array->data);
    free(array);
}

void* array_at(sArray *array, int offset)
{

}

void* array_frist(sArray *array)
{

}

void* array_last(sArray *array)
{

}

void* array_raw(sArray *array)
{
    return array->data;
}

int array_size(sArray *array)
{
    return array->length;
}

int array_elemSize(sArray *array)
{
    return array->elemSize;
}

int array_equal(sArray *a, sArray *b)
{

}

int array_not_equal(sArray *a, sArray *b)
{

}
