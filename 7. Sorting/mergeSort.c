//
//  main.c
//  mergeSort
//
//  Created by 이민성 on 2023/08/28.
//

#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int key;
} element;

void merge(element initList[], element mergedList[], int i, int m, int n);
void mergePass(element initList[], element mergedList[], int n, int s);
int rmergeSort(element a[], int link[], int left, int right);
int listMerge(element a[], int link[], int start1, int start2);

int main(void) {
    return 0;
}

void merge(element initList[], element mergedList[], int i, int m, int n)
{ // the sorted lists initList[i:m] and initList[m+1:n] are merged to obtain the sorted list mergeList [i:n]
    int j, k, t;
    j = m+1; // index for the second sublist
    k = i; // index for the merged list
    
    while (i <= m && j <= n) {
        if (initList[i].key <= initList[j].key)
            mergedList[k++] = initList[i++];
        else
            mergedList[k++] = initList[j++];
    }
    
    if (i > m)
    // mergedList[k:n] = initList[j:n]
        for (t = j; t <= n; t++)
            mergedList[t] = initList[t];
    else
    // mergedList[k:n] = initList[i:m]
        for (t = i; t <= m; t++)
            mergedList[k+t-i] = initList[t];
}

void mergePass(element initList[], element mergedList[], int n, int s)
{ // perform one pass of the merge sort, merge adjacent pairs of sorted segments from initList[] into mergedList[], n is the number of elements in the list, s is the size of each sorted segment
    int i, j;
    for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
        merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
    if (i  + s - 1 < n)
        merge(initList, mergedList, i, i + s - 1, n);
    else
        for (j = i; j <= n; j++)
            mergedList[j] = initList[j];
}

void mergeSort(element a[], int n)
{ // sort a[1:n] using the merge sort method
    int s = 1; // current segment size
    element extra[MAX_SIZE];
    
    while (s < n) {
        mergePass(a, extra, n, s);
        s *= 2;
        mergePass(extra, a, n, s);
        s *= 2;
    }
}

int rmergeSort(element a[], int link[], int left, int right)
{ // a[left:right] is to be sorted, link[i] is initially 0 for all i, returns the index of the first element in the sorted chain
    if (left >= right)
        return left;
    int mid = (left + right) / 2;
    return listMerge(a, link, rmergeSort(a, link, left, mid) /* sort left half */, rmergeSort(a, link, mid+1, right)); /* sort right half */
}

int listMerge(element a[], int link[], int start1, int start2)
{ // sorted chains beginning at start1 and start2, respectively, are merged; link[0] is used as a temporary header; returns start of merged chain
    int last1, last2, lastResult = 0;
    for (last1 = start1, last2 = start2; last1 && last2;) {
        if (a[last1].key <= a[last2].key) {
            link[lastResult] = last1;
            lastResult = last1;
            last1 = link[last1];
        }
        else {
            link[lastResult] = last2;
            lastResult = last2;
            last2 = link[last2];
        }
    }
    // attach remaining records to result chain
    if (last1 == 0)
        link[lastResult] = last2;
    else
        link[lastResult] = last1;
    return link[0];
}
