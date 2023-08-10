//
//  main.c
//  heap
//
//  Created by 이민성 on 2023/08/10.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 200 // 최대 히프 크기 + 1
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
    int key;
    // 다른 필드들
} element;

element heap[MAX_ELEMENTS];
int n = 0;

void push(element item, int * n);
element pop(int * n);

int main(void) {
    
    return 0;
}

void push(element item, int * n)
{ // insert item into a max heap of current size
    int i;
    if (HEAP_FULL(*n)) {
        fprintf(stderr, "The heap is full. \n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while ((i != 1) && (item.key > heap[i/2].key)) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}

element pop(int * n)
{ // delete element with the height key from the heap
    int parent, child;
    element item, temp;
    if (HEAP_EMPTY(*n)) {
        fprintf(stderr, "The heap is empty\n");
        exit(EXIT_FAILURE);
    }
    // save value of the element with the highest key
    item = heap[1];
    // use last element in heap to adjust heap
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while (child <= *n) {
        // find the larger child of the current parent
        if ((child < *n) && (heap[child].key < heap[child+1].key))
            child++;
        if (temp.key >= heap[child].key)
            break;
        // move to the next lower level
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}
