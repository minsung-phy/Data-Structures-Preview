//
//  main.c
//  SequemtialSearch
//
//  Created by 이민성 on 2023/08/24.
//

#include <stdio.h>

#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct {
    int key;
} element;

int seqsearch(element a[], int k, int n);
void verify1(element list1[], element list2[], int n, int m);
void verify2(element list1[], element list2[], int n, int m);
void swap(element *a, element *b);
int partition(element arr[], int low, int high);
void quickSort(element arr[], int low, int high);
void sort(element arr[], int n);

int main(void) {
    return 0;
}

int seqsearch(element a[], int k, int n)
{ // serach a[1:n]; return the least i such that a[i].key = k; return 0, if k is not in array
    int i;
    for (i = 1; i <= n && a[i].key != k; i++);
    if (i > n)
        return 0;
    return i;
}

void verify1(element list1[], element list2[], int n, int m)
{ // compare two unordered lists list1[1:n] and list2[1:m]
    int i, j, marked[MAX_SIZE];
    for (i = 1; i <= m; i++)
        marked[i] = FALSE;
    for (i = 1; i <= n; i++)
        if ((j = seqsearch(list2, m, list1[i].key)) == 0)
            printf("%d is not in list2\n", list1[i].key);
        else
            // check each of the other fields from list1[i] and list2[j], and print out any discrepancies
            marked[j] = TRUE;
    for (i = 1; i <= m; i++)
        if (!marked[i])
            printf("%d is not in list1\n", list2[i].key);
}

void verify2(element list1[], element list2[], int n, int m)
{ // same as verify1, but we sort list1 and list2 first
    int i, j;
    sort(list1, n);
    sort(list2, m);
    i = j = 1;
    while (i <= n && j <= m)
        if (list1[i].key < list2[i].key) {
            printf("%d is not in list 2\n", list1[i].key);
            i++;
        }
        else if (list1[i].key == list2[j].key) {
            // compare list1[i] and list2[j] on each of the other fields and report any discrepancies
            i++;
            j++;
        }
        else {
            printf("%d is not in list1\n", list2[j].key);
            j++;
        }
    for (; i <= n; i++)
        printf("%d is not in list2\n", list1[i].key);
    for (; j <= m; j++)
        printf("%d is not in list1\n", list2[j].key);
}

void swap(element *a, element *b)
{
    element temp = *a;
    *a = *b;
    *b = temp;
}

int partition(element arr[], int low, int high)
{
    int pivot = arr[high].key;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].key < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(element arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sort(element arr[], int n)
{
    quickSort(arr, 1, n); // Elements are indexed from 1
}
