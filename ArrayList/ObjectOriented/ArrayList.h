#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#define DEFAULT_INTIAL_CAPACITY 100
#define SPACE_RESIZE 50

#include <stdlib.h>
#include <string.h>

typedef void* (*forEachFuction)(void*, void*);

struct ArrayList {
    void* array;
    int nUsedElements;
    int capacity;
    int elementSize;

    void  (*destroyArrayList)(void*);
    int   (*getSize)(void*);
    int   (*addElement)(void* , void*);
    void* (*getElement)(void* , size_t);
    int   (*setElement)(void* , size_t , void*);
    void* (*forEach)(void* , forEachFuction , void*);
    void* (*toArray)(void*);
    int   (*addElements)(void* , const void* , size_t);
    
};



struct ArrayList* getArrayList(int , int);
void ArrayList_destroyArrayList(void*);
int ArrayList_getSize(void*);
int ArrayList_addElement(void* , void*);
void* ArrayList_getElement(void* , size_t);
int ArrayList_setElement(void* , size_t , void*);
void* ArrayList_forEach(void* , forEachFuction , void*);
void* ArrayList_toArray(void*);
int ArrayList_addElements(void* , const void* , size_t);

/*TODO*/
int ArrayList_removeElement(struct  ArrayList* , int); 
#endif