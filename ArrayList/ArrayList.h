#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#define DEFAULT_INTIAL_CAPACITY 100
#define SPACE_RESIZE 50

#include <stdlib.h>
#include <string.h>

struct ArrayList {
    void* array;
    int nUsedElements;
    int capacity;
    int elementSize;
};

typedef void* (*forEachFuction)(struct ArrayList*, void*);

struct ArrayList* getArrayList(int , int);
void destroyArrayList(struct ArrayList* );
int getSize(struct ArrayList* );
int addElement(struct ArrayList* , void*);
void* getElement(struct ArrayList* , size_t);
int setElement(struct ArrayList* , size_t , void*);
void* forEach(struct ArrayList* , forEachFuction , void*);
void* toArray(struct ArrayList*);
int addElements(struct ArrayList* , const void* , size_t);

/*TODO*/
int removeElement(struct  ArrayList* , int); 
#endif