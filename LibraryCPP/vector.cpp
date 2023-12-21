#include "vector.h"
#include <cstdlib>

struct Vector {
    Data* data;
    size_t size;
};

Vector* vector_create() {
    Vector* vector = new Vector;
    vector->data = nullptr;
    vector->size = 0;
    return vector;
}

void vector_delete(Vector* vector) {
    delete[] vector->data;
    delete vector;
}

Data vector_get(const Vector* vector, size_t index) {
    if (index < vector->size) {
        return vector->data[index];
    } else {
        exit(EXIT_FAILURE);
    }
}

void vector_set(Vector* vector, size_t index, Data value) {
    if (index < vector->size) {
        vector->data[index] = value;
    } else {
        exit(EXIT_FAILURE);
    }
}

size_t vector_size(const Vector* vector) {
    return vector->size;
}

void vector_resize(Vector* vector, size_t size) {
    if (size > 0) {
        Data* new_data = new Data[size];
        size_t min_size = (size < vector->size) ? size : vector->size;

        for (size_t i = 0; i < min_size; ++i) {
            new_data[i] = vector->data[i];
        }

        delete[] vector->data;
        vector->data = new_data;
        vector->size = size;
    } else {
        exit(EXIT_FAILURE);
    }
}