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

    self->destroyArrayList = ArrayList_destroyArrayList;
    self->getSize          = ArrayList_getSize;
    self->addElement       = ArrayList_addElement;
    self->getElement       = ArrayList_getElement;
    self->setElement       = ArrayList_setElement;
    self->forEach          = ArrayList_forEach;
    self->toArray          = ArrayList_toArray;
    self->addElements      = ArrayList_addElements;

    return self;
}

void ArrayList_destroyArrayList(void* obj) {
    struct ArrayList* self = obj;
    
    if (self != NULL) {
        if (self->array != NULL) {
            free(self->array);
        }
        free(self);
    }
}

int ArrayList_addElement(void* obj, void* value) {
    struct ArrayList* self = obj;

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

void* ArrayList_getElement(void* obj, size_t position) {
    struct ArrayList* self = obj;

    if (self == NULL) {
        return NULL;
    }

    if (position >= self->getSize(self)) {
        return NULL;
    }

    return (self->array) + (position * self->elementSize);
}

int ArrayList_setElement(void* obj, size_t position, void* value) {
    struct ArrayList* self = obj;

    if (self == NULL) {
        return -1;
    }

    if (value == NULL) {
        return -2;
    }

    if (position >= self->getSize(self)) {
        return -4;
    }

    memcpy(((self->array) + (position * self->elementSize)), value, self->elementSize);
    return 0;
}

void* ArrayList_forEach(void* obj, forEachFuction function, void* data) {
    struct ArrayList* self = obj;

    if (self == NULL) {
        return NULL;
    }
    return function(self, data);
}


int ArrayList_getSize(void* obj) {
    struct ArrayList* self = obj;

    if (self == NULL) {
        return -1;
    }

    return self->nUsedElements;
}



void* ArrayList_toArray(void* obj) {
    struct ArrayList* self = obj;

    size_t totalSize = self->getSize(self) * self->elementSize;
    void *dest = calloc(self->getSize(self), self->elementSize);
    memcpy(dest, self->array, totalSize);
    return dest;
}

int ArrayList_addElements(void* obj, const void* src, size_t nElements) {
    struct ArrayList* self = obj;

    if (self == NULL) {
        return -1;
    }

    if (src == NULL) {
        return -2;
    }

    if (nElements <= 0) {
        return -5;
    }

    size_t newNUsedElements = self->getSize(self) + nElements;

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