//
//  main.c
//  magicsquare
//
//  Created by 이민성 on 2023/07/20.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15 // 정방형의 최대 크기

void main(void)
{ // 정방형을 반복적으로 생성
    static int square[MAX_SIZE][MAX_SIZE];
    int i, j, row, column; // 지수
    int count; // 계수
    int size; // 정방형의 크기
    
    printf("Enter the size of the square: "); scanf("%d", &size);
    // 입력에 오류가 있는지 체크
    if (size < 1 || size > MAX_SIZE + 1) {
        fprintf(stderr, "Error! Size is out of range\n");
        // exit(1);
    }
    if (!(size % 2)) {
        fprintf(stderr, "Error! Size is even\n");
        exit(1);
    }
    for (i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            square[i][j] = 0;
    square[0][(size-1) / 2] = 1; // 첫 번째 행의 중앙에 1을 넣는다
    // i와 j는 현재 위치
    i = 0;
    j = (size - 1) / 2;
    for (count = 2; count <= size * size; count++)
    {
        // 삼항연산자 -> 조건 ? 참일때의 값: 거짓일때의 값;
        row = (i-1 < 0) ? (size - 1): (i - 1); // 위로
        column = (j-1 < 0) ? (size - 1): (j - 1); // 왼쪽으로
        if (square[row][column]) // 아래로
            i = (++i) % size;
        else
        {
            i = row;
            j = (j-1 < 0) ? (size - 1): --j; // j = column;과 같은 뜻
        }
        square[i][j] = count;
    }
    // 정방형을 출력
    printf("Magic Square of size %d: \n\n", size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            printf("%5d", square[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
