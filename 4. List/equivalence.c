//
//  main.c
//  equivalence
//
//  Created by 이민성 on 2023/08/01.
//

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
if (!( (p) = malloc(s) )) \
    { \
    fprintf(stderr, "Insufficient memory"); \
    exit(EXIT_FAILURE); \
    }

#define MAX_SIZE 24
#define FALSE 0
#define TRUE 1

typedef struct {
    int data;
    struct node * link;
} node;

typedef struct node * nodePointer;

int main(void)
{
    short int out[MAX_SIZE];
    nodePointer seq[MAX_SIZE];
    nodePointer x, y, top;
    int i, j, n;
    
    printf("Enter the size (<= %d) ", MAX_SIZE);
    scanf("%d", &n);
    for (i = 0; i < n; i++) { // seq와 out을 초기화
        out[i] = TRUE;
        seq[i] = NULL;
    }
    
    // 단계 1: 동치 쌍들을 입력
    printf("Enter a pair of numbers (-1 -1 to quit): "); scanf("%d%d", &i, &j);
    while (i >= 0) {
        MALLOC(x, sizeof(*x));
        x->data = j;
        x->link = seq[i];
        seq[i] = x;
        MALLOC(x, sizeof(*x));
        x->data = i;
        x->link = seq[j];
        seq[j] = x;
        printf("Enter a pair of numbers (-1 -1 to quit): "); scanf("%d%d", &i, &j);
    }
    
    // 단계 2: 동치 부류들을 출력
    for (i = 0; i < n; i++)
        if (out[i]) {
            printf("\nNew class: %5d", i);
            out[i] = FALSE; // 부류들을 FALSE로 설정
            x = seq[i];
            top = NULL; // 스택을 초기화
            for(;;) { // 나머지 부류 찾기
                while (x) { // 리스트 처리
                    j = x->data;
                    if (out[j]) {
                        printf("%5d", j); out[j] = FALSE;
                        y = x->link;
                        x->link = top;
                        top = x;
                        x = y;
                    }
                    else x = x->link;
                }
                if (!top)
                    break;
                x = seq[top->data];
                top = top->link; // 스택에서 제거
            }
        }
    return 0;
}


