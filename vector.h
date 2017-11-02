#ifndef VECTOR_H
#define VECTOR_H

#include "iterator.h"

#define VECTOR_MIN_CAPACITY 2
#define VECTOR_GROWTH_FACTOR 2
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct _vector_element_t
{
	void *data;
}vector_element_t;

typedef iterator_t vector_iterator_t;
typedef size_t vector_size_t;
typedef int (*data_dtor_func_t)(void *);
typedef void * (*data_ctor_func_t)(void *);

typedef struct
{
	data_ctor_func_t ctor;
	data_dtor_func_t dtor;
}vector_data_ops_t;

typedef struct _vector_t
{
	vector_size_t capacity;
	vector_size_t size;
	vector_size_t obj_size;
	void *data;
	vector_data_ops_t data_ops;
}vector_t;

vector_t *
vector_create(vector_size_t capacity, vector_size_t element_size, data_ops_t ops);

int
vector_destroy(vector_t *v);

int
vector_push_back(vector_t *v, void *e);

void* _vector_offset(vector_t *vector, size_t index);

void _vector_assign(vector_t *vector, size_t index, void* element);


void safe_free(void **pp);
#define sfree(p) safe_free((void**)&(p))

#endif
