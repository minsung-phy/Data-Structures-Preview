//
//  main.c
//  heapSort
//
//  Created by 이민성 on 2023/08/30.
//

#include <stdio.h>

#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

typedef struct {
    int key;
} element;

int main(void) {
    
    return 0;
}

void adjust(element a[], int root, int n) // 최대 히프의 조정
{ // adjust the binary tree to establish the heap
    int child, rootkey;
    element temp;
    temp = a[root];
    rootkey = a[root].key;
    child = 2 * root; // left child
    while (child <= n) {
        if ((child < n) && (a[child].key < a[child+1].key))
            child++;
        if (rootkey > a[child].key) // compare root and max child
            break;
        else {
            a[child / 2] = a[child]; // move to parent
            child *= 2;
        }
    }
    a[child / 2] = temp;
}

void heapSort(element a[], int n)
{ // perform a heap sort on a[1:n]
    int i, j;
    element temp;
    for (i = n/2; i > 0; i--)
        adjust(a, i, n);
    for (i = n-1; i > 0; i--) {
        SWAP(a[1], a[i+1], temp);
        adjust(a, 1, i);
    }
}
