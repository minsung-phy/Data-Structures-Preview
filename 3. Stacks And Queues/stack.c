//
//  main.c
//  stack
//
//  Created by 이민성 on 2023/07/25.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 // 스택의 최대 크기
#define INVALID_KEY -1

typedef struct {
    int key;
    // 다른 필드
} element;

element stack[MAX_STACK_SIZE];

int top = -1; // if top is -1, it means the stack is empty

void push(element item);
void stackFull(void);
element pop(void);
element stackEmpty(void);

int main(void) {
    int i;
    element e;
    
    for (i = 0; i < 5; i++)
    {
        e.key = i;
        push(e);
        printf("key %d inserted into the stack.\n", e.key);
    }
    
    for (i = 0; i < 5; i++)
    {
        e = pop();
        printf("key %d deleted from the stack.\n", e.key);
    }
    return 0;
}

void push(element item)
{ // 전역 stack에 item을 삽입
    if (top >= MAX_STACK_SIZE-1)
        stackFull(); // error handler
    stack[++top] = item;
}

void stackFull(void)
{
    fprintf(stderr, "Stack is full, cannot add element");
    exit(EXIT_FAILURE);
}

element pop(void)
{ // stack의 최상위 원소를 삭제하고 반환
    if (top == -1)
        return stackEmpty(); // returns an error key
    return stack[top--];
}

element stackEmpty(void)
{
    element e;
    e.key = INVALID_KEY;
    return e;
}
