    //
//  main.c
//  algorithm
//
//  Created by 이민성 on 2023/07/18.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 101
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMPARE(x, y) (((x) < (y)) ? -1: ((x) == (y)) ? 0: 1)

void sort(int[], int); // selection sort
int binsearch(int list[], int searchnum, int left, int right);
void perm (char * list, int i, int n);
int binsearch_recursion(int list[], int searchnum, int left, int right);

int main(void)
{
    int i, n;
    int list[MAX_SIZE];
    printf("Enter the number of numbers generate: "); scanf("%d", &n);
    if (n < 1 || n > MAX_SIZE) {
        fprintf(stderr, "Improper value of n\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < n; i++) {
        list[i] = rand() % 1000;
        printf("%d  ", list[i]);
    }
    sort(list, n);
    printf("\n Sorted array: \n");
    for (i = 0; i < n; i++) // print out sorted numbers
        printf("%d  ", list[i]);
    printf("\n");
    return 0;
}

void sort(int list[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n-1; i++) {
        min = i;
        for ( j = i+1; j < n; j++)
            if (list[j] < list[min])
                min = j;
        SWAP(list[i], list[min], temp);
    }
}

int binsearch(int list[], int searchnum, int left, int right)
{
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        switch (COMPARE(list[middle], searchnum))
        {
            case -1: left = middle + 1;
                break;
            case 0: return middle;
            case 1: right = middle - 1;
        }
    }
    return -1;
//}
//
//int binsearch2(int list[], int searchnum, int left, int right)
//{
//    int middle;
//    while (left <= right)
//    {
//        middle = (left + right) / 2;
//        if (searchnum < list[middle])
//            right = middle - 1;
//        else if (searchnum == list[middle])
//            return middle;
//        else
//            left = middle + 1;
//    }
//    return -1;
//}

int binsearch_recursion(int list[], int searchnum, int left, int right)
{
    // search list[0] <= list[1] <= ... <= list[n-1] for searchnum. Return its position if found, Otherwise return -1
    int middle;
    if (left <= right)
    {
        middle = (left + right) / 2;
        switch (COMPARE(list[middle], searchnum))
        {
            case -1: return binsearch(list, searchnum, middle + 1, right);
            case 0: return middle;
            case 1: return binsearch(list, searchnum, left, middle + 1);
        }
    }
    return -1;
}

void perm (char * list, int i, int n)
{ // generate all the permutations of list[i] to list[n]
    int j, temp;
    if (i == n)
    {
        for (j = 0; j <= n; j++)
            printf("%c", list[j]);
        printf("    ");
    }
    else
    { // list[i] to list[n] has more than one permutation, generate thesr recursively
        for (j = i; j <= n; j++)
        {
            SWAP(list[i], list[j], temp);
            perm(list, i+1, n);
            SWAP(list[i], list[j], temp);
        }
    }
}
