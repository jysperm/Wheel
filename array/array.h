#ifndef H_JYDS_ARRAY
#define H_JYDS_ARRAY

typedef struct {
    int elemSize;
    int length;
    void *data;
} Array;

Array* array_create(int elemSize, int length);
Array* array_createWithDefaultValue(int elemSize, int length, void *defaultValue);
Array* array_copy(Array *other);
void array_override(Array *source, Array *target);
void array_free(Array *array);

void* array_at(Array *array, int offset);
void* array_frist(Array *array);
void* array_last(Array *array);
void* array_raw(Array *array);

int array_size(Array *array);
int array_elemSize(Array *array);


#endif // H_JYDS_ARRAY
