//
//  main.c
//  factorial
//
//  Created by 이민성 on 2023/07/19.
//

#include <stdio.h>

int factorial(int n)
{
    if (n > 1)
        return n * factorial(n-1);
    else
        return 1;
}

int main(void) {
    int i, result;
    printf("정수 입력: "); scanf("%d", &i);
    if (i < 0)
    {
        printf("0이상의 정수를 입력하세요.\n");
        return -1;
    }
    result = factorial(i);
    printf("%d!의 계산결과: %d\n", i, result);
    return 0;
}
