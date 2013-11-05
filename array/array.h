#ifndef H_JYDS_ARRAY
#define H_JYDS_ARRAY

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int elemSize;
    int length;
    void *data;
} sArray;

sArray* array_create(int elemSize, int length);
sArray* array_create_defaults(int elemSize, int length, void *defaultValue);
sArray* array_copy(sArray *other);
void array_override(sArray *target, sArray *source);
void array_free(sArray *array);

void* array_at(sArray *array, int offset);
void* array_frist(sArray *array);
void* array_last(sArray *array);
void* array_raw(sArray *array);

int array_size(sArray *array);
int array_elemSize(sArray *array);

int array_equal(sArray *a, sArray *b);
int array_not_equal(sArray *a, sArray *b);

#ifdef __cplusplus
}	// extern "C" {
#endif

#endif // H_JYDS_ARRAY
