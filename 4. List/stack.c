//
//  main.c
//  stack
//
//  Created by 이민성 on 2023/07/31.
//

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
if (!( (p) = malloc(s) )) \
    { \
    fprintf(stderr, "Insufficient memory"); \
    exit(EXIT_FAILURE); \
    }
#define MAX_STACKS 10 // 스택의 최대 수
#define INVALID_KEY -1
typedef struct {
    int key;
    // 기타 필드
} element;

//typedef struct stack *stackPointer;
//
//typedef struct {
//    element data;
//    stackPointer link;
//} stack;

// stackPointer top[MAX_STACKS];

struct stack{
    element data;
    struct stack * link;
};

struct stack * top[MAX_STACKS];

void push (int i, element item);
element pop (int i);
element stackEmpty(void);

int main(void) {
    return 0;
}

void push (int i, element item)
{ // i번째 스택에 원소를 삽입
    struct stack * temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = item;
    temp->link = top[i];
    top[i] = temp;
}

element pop (int i)
{ // i번째 스택으로부터 top 원소를 삭제
    struct stack * temp = top[i];
    element item;
    if (!temp)
        return stackEmpty();
    item = temp->data;
    top[i] = temp->link;
    free(temp);
    return item;
}

element stackEmpty(void)
{
    element e;
    e.key = INVALID_KEY;
    return e;
}
