//
//  main.c
//  DynamicallyAllocated_One-dimensionalArray
//
//  Created by 이민성 on 2023/07/21.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define MALLOC(p,s) \
if (!( (p) = malloc(s) )) \
    { \
    fprintf(stderr, "Insufficient memory"); \
    exit(EXIT_FAILURE); \
    }

void sort(int[], int); // selection sort

int main(void)
{
    int i, n, *list;
    printf("Enter the number of numbers to generate: "); scanf("%d", &n);
    if (n < 1 || n > MAX_SIZE)
    {
        fprintf(stderr, "Improper value of n\n");
        exit(EXIT_FAILURE);
    }
    MALLOC(list, n * sizeof(int));
    for (i = 0; i < n; i++) {
        list[i] = rand() % 1000;
        printf("%d  ", list[i]);
    }
    sort(list, n);
    printf("\n Sorted array: \n");
    for (i = 0; i < n; i++) // print out sorted numbers
        printf("%d  ", list[i]);
    printf("\n");
    
    free(list);
    
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
