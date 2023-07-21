//
//  main.c
//  array
//
//  Created by 이민성 on 2023/07/21.
//

#include <stdio.h>
#define MAX_SIZE 100

float sum(float list[], int n);
float input[MAX_SIZE], answer;
void print1(int *ptr, int rows);

void main(void)
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
        input[i] = i;
    answer = sum(input, MAX_SIZE);
    printf("The sum is: %f\n", answer);
}

float sum(float list[], int n)
{
    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += list[i];
    return tempsum;
}

void print1(int *ptr, int rows)
{ /* 포인터를 사용해서 1차원 배열을 출력*/
    int i;
    printf("Address Contents\n");
    for (i = 0; i < rows; i++)
        printf("%8u%5d\n", ptr+i, *(ptr+1));
    printf("\n");
}
