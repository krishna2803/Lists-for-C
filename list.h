#ifndef LISTS_INCLUDED
    #define LISTS_INCLUDED
typedef struct {
    int* array;
    int size;
    int stack;
} list;

list createList(int size);
list createUnitList(int size);

void printList(list l);
void appendElement(list* l, int e);
void removeIndex(list* l, int index);

#endif
