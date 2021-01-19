#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list createList(int size) {
    list l;
    l.size = size;
    l.stack = 0;
    l.array = (int*) malloc(sizeof(int) * l.size);
    if (!l.array) perror("memory allocation failed!");
    return l;
}

list createUnitList(int size) {
    list l;
    l.size = size;
    l.stack = 0;
    l.array = (int*) malloc(sizeof(int) * l.size);
    if (!l.array) perror("memory allocation failed!");
    for(int i = 0; i < l.size; i++) *(l.array+i) = 1;
    return l;
}

void printList(list l) {
    printf("[");
    for(int i = 0; i < l.size - 1; printf("%d, ", *(l.array+i)), i++);
    printf("%d]\n", l.array[l.size-1]);
}

void appendElement(list* l, int e) {
    if (l->stack == l->size) l->array = (int*) realloc(l->array, (l->size *= 2) * sizeof(int));
    *(l->array+(l->stack++)) = e;
    // printf("stack = %d, size = %d\n", l->stack, l->size);
}

void removeIndex(list* l, int index) {
    if (index < 0 || index > l->size) return;
    for(int i = index; i < l->size - 1; i++) l->array[i] = l->array[i+1];
    l->array[l->size-1] = 0;
    l->stack--;
}
