#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
void printArrayListString(void* obj, void* data) {
    printf("%s, ", *((char**)obj));
}

void sumChar(void* obj, void* data) {
    int *sum = data;
    *sum += strlen(*((char**)obj));
}

int main(int argc, char **argv) {
    char* f = "3", *s = "44";
    char* arr[] = {"jednen", "dwa", "trzy", "cztery", "piec"};

    struct ArrayList* test = getArrayList(sizeof(char*), 1);

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
    puts("");
    test->forEach(test, sumChar, &sum);
    printf("Number of characters: %d \n", sum);
    char** tab = test->toArray(test);
    for(int i = 0; i < test->getSize(test); i++) {
        printf("%s,  ", tab[i]);
    }
    free(tab);
    test->destroyArrayList(test);

    return 0;
}
