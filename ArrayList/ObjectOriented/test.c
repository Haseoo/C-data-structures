#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
void* printArrayListInt(void* obj, void* data) {
    struct ArrayList* self = obj;

    if (self == NULL) {
        return NULL;
    }

    int size = self->getSize(self);

    for(int i = 0; i < size; i++) {
        printf("%d, ", ((int*)self->array)[i]);
    }

    return NULL;
}

void* sumInt(void* obj, void* data) {
    struct ArrayList* self = obj;

    if (self == NULL) {
        return NULL;
    }

    if (data == NULL) {
        return NULL;
    }

    int *sum = data;
    int size = self->getSize(self);

    for(int i = 0; i < size; i++) {
        *sum += ((int*)self->array)[i];
    }
    printf("\n");

    return NULL;
}

int main(int argc, char **argv) {
    int f = 3, s = 44;
    int arr[] = {1, 2, 3, 4, 5};

    struct ArrayList* test = getArrayList(sizeof(int), 1);

    test->addElement(test, &f);
    test->addElement(test, &f);
    test->addElements(test, arr, 5);
    test->addElement(test, &f);
    test->addElement(test, &f);
    test->addElement(test, &f);
    test->addElement(test, &s);
    test->addElement(test, &s);
    test->addElement(test, &s);
    test->setElement(test, 0, &f);
    int* ff = ((int*)test->getElement(test, 1));
    int sum = 0;

    printf("%d\n", *ff);
    test->forEach(test, printArrayListInt, NULL);
    test->forEach(test, sumInt, &sum);
    printf("%d \n", sum);
    int* tab = test->toArray(test);
    for(int i = 0; i < test->getSize(test); i++) {
        printf("%d,  ", tab[i]);
    }
    free(tab);
    test->destroyArrayList(test);

    return 0;
}
