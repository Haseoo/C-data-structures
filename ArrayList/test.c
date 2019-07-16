#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
void printArrayListInt(struct ArrayList* self, void* data) {
    printf("%d, ", *((int*)self));
}

void sumInt(struct ArrayList* self, void* data) {

    if (data == NULL) {
        return;
    }
    *((int*)data) += *((int*)self);
}

int main(int argc, char **argv) {
    int f = 3, s = 44;
    int arr[] = {1, 2, 3, 4, 5};

    struct ArrayList* test = getArrayList(sizeof(int), 1);

    addElement(test, &f);
    addElement(test, &f);
    addElements(test, arr, 5);
    addElement(test, &f);
    addElement(test, &f);
    addElement(test, &f);
    addElement(test, &s);
    addElement(test, &s);
    addElement(test, &s);
    setElement(test, 0, &f);
    int* ff = ((int*)getElement(test, 1));
    int sum = 0;

    printf("%d\n", *ff);
    forEach(test, printArrayListInt, NULL);
    puts("");
    forEach(test, sumInt, &sum);
    printf("Sum: %d \n", sum);
    int* tab = toArray(test);
    for(int i = 0; i < getSize(test); i++) {
        printf("%d,  ", tab[i]);
    }
    free(tab);
    destroyArrayList(test);

    return 0;
}
