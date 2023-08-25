//
//  main.c
//  quickSort
//
//  Created by 이민성 on 2023/08/25.
//

#include <stdio.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

typedef struct {
    int key;
} element;

void quickSort(element a[], int left, int right)
{ // sort a[left:right] into nondecreasing order on the key field; a[left].key is arbitrarily chosen as the pivot key; it is assumed that a[left].key <= a[right+1].key
    int pivot, i, j;
    element temp;
    if (left < right) {
        i = left; j = right + 1;
        pivot = a[left].key;
        do { // search for keys from the left and right sublists, swapping out-of-order elements until the left and right boundaries cross or meet
            do i++; while (a[i].key < pivot);
            do j--; while (a[j].key > pivot);
            if (i < j) SWAP(a[i], a[j], temp);
        } while (i < j);
        SWAP(a[left], a[j], temp);
        quickSort(a, left, j-1);
        quickSort(a, j+1, right);
    }
}

int main(void) {
    return 0;
}
