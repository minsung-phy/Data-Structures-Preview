//
//  main.c
//  hanoi
//
//  Created by 이민성 on 2023/07/19.
//

#include <stdio.h>

void hanoi(int n, char from, char middle, char to);

int count = 0;

int main(void) {
    int n;
    printf("원판의 개수를 입력하시오: "); scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    printf("총 이동 횟수: %d\n", count);
    return 0;
}

void hanoi(int n, char from, char middle, char to)
{
    if (n == 1)
    {
        printf("%d번을 %c에서 %c로 이동\n", n, from, to);
        count++;
    }
    else
    {
        hanoi(n-1, from, to, middle);
        printf("%d번을 %c에서 %c로 이동\n", n, from, to);
        count++;
        hanoi(n-1, middle, from, to);
    }
}
