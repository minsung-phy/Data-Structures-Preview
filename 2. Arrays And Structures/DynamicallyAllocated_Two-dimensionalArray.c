//
//  main.c
//  DynamicallyAllocated_Two-dimensionalArray
//
//  Created by 이민성 on 2023/07/21.
//

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
if (!( (p) = malloc(s) )) \
    { \
    fprintf(stderr, "Insufficient memory"); \
    exit(EXIT_FAILURE); \
    }

/* calloc 함수: 사용자가 지정한 양의 메모리를 할당하고 할당된 메모리를 0으로 초기화하는 함수, 할당된 메모리의 시작에 대한 포인터를 반환한다. 할당을 위한 메모리가 충분하지 않은 경우에 반환되는 값은 NULL이다.
int *x;
x = calloc(n, sizeof(int)); */

#define CALLOC(p,n,s) \
if (!((p) = calloc(n,s))) \
    { \
    fprintf(stderr, "Insufficient memory"); \
    exit(EXIT_FAILURE); \
    }

/* realloc 함수: malloc이나 calloc으로 이미 할당된 크기를 재조정한다. 포인터 p가 가리키는 메모리 블록의 크기를 s로 변경한다. 크기 조정을 할 수 있을 때는 새로운 블록의 시작에 대한 포인터를 반환하고, 크기 조정을 할 수 없을 때는 원래 블록은 변경되지 않고 함수는 NULL값을 반환한다.
 realloc(p, s) */

#define REALLOC(p, s) \
if (!((p) = realloc(p,s))) \
    { \
    fprintf(stderr, "Insufficient memory"); \
    exit(EXIT_FAILURE); \
    }

int** make2dArray(int rows, int cols)
{ /* create a two dimensional rows x cols array */
    int **x, i;
    
    /* get memory for row pointers */
    MALLOC(x, rows * sizeof(*x));
    
    /* get memory for each row */
    for (i = 0; i < rows; i++)
        MALLOC(x[i], cols * sizeof(**x));
    return x;
}

int main(void) {

    return 0;
}
