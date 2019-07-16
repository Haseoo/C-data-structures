#include "ArrayList.h"
struct ArrayList* getArrayList(int elementSize, int intialCapacity) {
    if (elementSize <= 0) {
        return NULL;
    }

    struct ArrayList* self = malloc(sizeof(struct ArrayList));

    if (self == NULL) {
        return NULL;
    }

    self->elementSize = elementSize;
    self->capacity = ((intialCapacity >= 0) ? intialCapacity : DEFAULT_INTIAL_CAPACITY);
    self->nUsedElements = 0;

    self->array = calloc(self->capacity, elementSize);

    if (!(self->array)) {
        free(self);
        return NULL;
    }

    return self;
}

void destroyArrayList(struct ArrayList* self) {
    if (self != NULL) {
        if (self->array != NULL) {
            free(self->array);
        }
        free(self);
    }
}

int addElement(struct ArrayList* self, void* value) {
    if (self == NULL) {
        return -1;
    }

    if (value == NULL) {
        return -2;
    }

    if (self->capacity <= self->nUsedElements) {
        self->capacity += SPACE_RESIZE;
        self->array = realloc(self->array, self->capacity * self->elementSize);
        if (self->array ==  NULL) {
            return -3;
        }
    }
    memcpy(((self->array) + (self->nUsedElements * self->elementSize)), value, self->elementSize);
    self->nUsedElements++;

    return 0;
}

void* getElement(struct ArrayList* self, size_t position) {
    if (self == NULL) {
        return NULL;
    }

    if (position >= getSize(self)) {
        return NULL;
    }

    return (self->array) + (position * self->elementSize);
}

int setElement(struct ArrayList* self, size_t position, void* value) {
    if (self == NULL) {
        return -1;
    }

    if (value == NULL) {
        return -2;
    }

    if (position >= getSize(self)) {
        return -4;
    }

    memcpy(((self->array) + (position * self->elementSize)), value, self->elementSize);
    return 0;
}

void *forEach(struct ArrayList* self, forEachFuction function, void* data) {
    if (self == NULL) {
        return NULL;
    }

    int iterations = getSize(self);
    for (int i = 0; i < iterations; i++) {
        function(self->array + (i * self->elementSize), data);
    }

    return data;
}


int getSize(struct ArrayList* self) {
    if (self == NULL) {
        return -1;
    }

    return self->nUsedElements;
}



void* toArray(struct ArrayList* self) {
    size_t totalSize = getSize(self) * self->elementSize;
    void *dest = calloc(getSize(self), self->elementSize);
    memcpy(dest, self->array, totalSize);
    return dest;
}

int addElements(struct ArrayList* self, const void* src, size_t nElements) {
    if (self == NULL) {
        return -1;
    }

    if (src == NULL) {
        return -2;
    }

    if (nElements <= 0) {
        return -5;
    }

    size_t newNUsedElements = getSize(self) + nElements;

    if (newNUsedElements >= self->capacity) {
        int newCapacity = newNUsedElements + 1;
        self->capacity = ((newCapacity > SPACE_RESIZE) ? newCapacity : SPACE_RESIZE);
        self->array = realloc(self->array, self->capacity * self->elementSize);
        if (self->array ==  NULL) {
            return -3;
        }
    }

    memcpy(((self->array) + (self->nUsedElements * self->elementSize)), src, self->elementSize * nElements);
    self->nUsedElements = newNUsedElements;
    return 0;
}