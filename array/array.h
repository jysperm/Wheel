#ifndef H_JYDS_ARRAY
#define H_JYDS_ARRAY

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int elemSize;
    int length;
    void *data;
} tArray;

tArray* array_create(int elemSize, int length);
tArray* array_create_defaults(int elemSize, int length, void *defaultValue);
tArray* array_copy(tArray *other);
void array_override(tArray *target, tArray *source);
void array_free(tArray *array);

void* array_at(tArray *array, int offset);
void* array_frist(tArray *array);
void* array_last(tArray *array);
void* array_raw(tArray *array);

int array_size(tArray *array);
int array_elemSize(tArray *array);

int array_equal(tArray *a, tArray *b);
int array_not_equal(tArray *a, tArray *b);

#ifdef __cplusplus
}   // extern "C" {
#endif

#endif // H_JYDS_ARRAY
