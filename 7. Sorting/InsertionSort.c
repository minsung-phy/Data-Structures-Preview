//
//  main.c
//  InsertionSort
//
//  Created by 이민성 on 2023/08/25.
//

#include <stdio.h>

typedef struct {
    int key;
} element;

void insert(element e, element a[], int i);
void insertionSort(element a[], int n);

int main(void) {
    return 0;
}

void insert(element e, element a[], int i)
{ // insert e into the orderde list a[1:i] such that the resulting list a[1:i+1] is also ordered, the array a must have space allocated for at least i+2 elements
    a[0] = e;
    while (e.key < a[i].key)
    {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = e;
}

void insertionSort(element a[], int n)
{ // a[1:n]을 비감소 키 순서대로 정렬
    int j;
    for (j = 2; j <= n; j++) {
        element temp = a[j];
        insert(temp, a, j-1);
    }
}
