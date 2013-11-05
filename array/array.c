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
