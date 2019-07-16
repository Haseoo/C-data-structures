#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
void* printArrayListString(void* obj, void* data) {
    struct ArrayList* self = obj;

    if (self == NULL) {
        return NULL;
    }

    int size = self->getSize(self);
    printf("{");
    for(int i = 0; i < size; i++) {
        printf("%s,", ((char**)self->array)[i]);
    }
    printf("}\n");

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
        *sum += strlen(((char**)self->array)[i]);
    }
    printf("\n");

    return NULL;
}

int main(int argc, char **argv) {
    char* f = "3", *s = "44";
    char* arr[] = {"jednen", "dwa", "trzy", "cztery", "piec"};

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
    int sum = 0;

    test->forEach(test, printArrayListString, NULL);
    test->forEach(test, sumInt, &sum);
    printf("Number of characters: %d \n", sum);
    char** tab = test->toArray(test);
    for(int i = 0; i < test->getSize(test); i++) {
        printf("%s,  ", tab[i]);
    }
    free(tab);
    test->destroyArrayList(test);

    return 0;
}
