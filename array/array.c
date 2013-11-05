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
