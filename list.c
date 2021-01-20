#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list createList(int size) {
    list l = {(int*) malloc(sizeof(int) * size), size, 0};
    if (!l.array) perror("memory allocation failed!");
    return l;
}

list createUnitList(int size) {
    list l = createList(size);
    for(int i = 0; i < l.size; i++) *(l.array+i) = 1;
    return l;
}

void printList(list l) {
    if (l.stack <= 0) {
        printf("[]\n");
        return;
    }
    printf("[");
    for(int i = 0; i < l.stack - 1; printf("%d, ", *(l.array+(i++))));
    printf("%d]\n", *(l.array+l.stack-1));
}

void appendElement(list* l, int e) {
    if (l->stack == l->size) l->array = (int*) realloc(l->array, (l->size *= 2) * sizeof(int));
    *(l->array+(l->stack++)) = e;
}

void appendIndex(list* l, int index, int e) {
    if (index < 0 || index >= l->size) return;
    appendElement(l, 0);
    for(int i = l->stack; i > index; i--) *(l->array+i) = *(l->array+i-1);
    *(l->array+index) =  e;
}

void removeIndex(list* l, int index) {
    if (index < 0 || index >= l->size) return;
    for(int i = index; i < l->size - 1; i++) l->array[i] = l->array[i+1];
    l->array[l->size-1] = 0;
    l->stack--;
}

void reverseList(list* l) {
    if (l->stack <= 0) return;
    for(int i = 0; i < l->stack >> 1; i++) {
        int temp = *(l->array+i);
        *(l->array+i) = *(l->array+(l->stack-i-1));
        *(l->array+(l->stack-i-1)) = temp;
    }
}
