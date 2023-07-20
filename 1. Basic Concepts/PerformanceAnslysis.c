//
//  main.c
//  PerformanceAnslysis
//
//  Created by 이민성 on 2023/07/19.
//

#include <stdio.h>
#define MAX_SIZE 15

int count = 0;

float abc(float a, float b, float c) // 단순 산술 함수
{
    return a+b+b*c+(a+b-c) / (a+b)+4.00;
}

float sum(float list[], int n) // 리스트에 있는 수를 합산하기 위한 반복 함수
{
    float tempsum = 0;
    int i;
    for (i = 0; i < n; i++)
        tempsum += list[i];
    return tempsum;
}

float rsum(float list[], int n) // 리스트에 있는 수를 합산하기 위한 순환 함수
{
    if (n) return rsum(list, n-1) + list[n-1];
    return 0;
}

float sum_count(float list[], int n)
// count를 가진(실행 시간을 측정하기 위한) 리스트에 있는 수를 합산하기 위한 반복 함수
{
    float tempsum = 0; count++; // 지정문을 위한 선언
    int i;
    for (i = 0; i < n; i++)
    {
        count++;
        tempsum += list[i]; count++; // 지정문을 위한 연산
    }
    count++; // for 문의 마지막 실행
    count ++; /* 반환을 위한 명령문 */ return tempsum;
}

float sum_count_simple(float list[], int n)
// count를 가진(실행 시간을 측정하기 위한) 리스트에 있는 수를 합산하기 위한 반복 함수를 간단히 표현(count를 쉽게 계산하기 위해)
{
    // float tempsum = 0;
    int i;
    for (i = 0; i < n; i++)
        count += 2;
    count += 3;
    return 0;
}

float rsum_count(float list[], int n) // count문이 첨가된 리스트에 있는 수를 합산하기 위한 순환 함수
{
    count++; // if 문을 위한 명령문
    if (n)
    {
        count++; // 반환과 호출을 위한 명령문
        return rsum(list, n-1) + list[n-1];
    }
    count++;
    return list[0];
}

void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols) // 행렬의 덧셈
{
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            c[i][j] = a[i][j] + b[i]    [j];
}

void add_count(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols) // count문이 첨가된 행렬의 덧셈
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        count++; // i for 루프를 위한 명령문
        for (j = 0; j < cols; j++)
        {
            count++; // j for 루프를 위한 명령문
            c[i][j] = a[i][j] + b[i][j];
            count++; // 지정문을 위한 명령문
        }
        count++; // for 루프에 대한 마지막 j
    }
    count++; // for 루프에 대한 마지막 i
}

void add_count_simple(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols) // count문이 첨가된 행렬의 덧셈의 단순화
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            count += 2;
        count += 2;
    }
    count++;
}


int main(void) {
    
    return 0;
}


