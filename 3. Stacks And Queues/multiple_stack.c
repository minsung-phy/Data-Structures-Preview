//
//  main.c
//  multiple_stack
//
//  Created by 이민성 on 2023/07/27.
//

#include <stdio.h>

typedef struct {
    int a;
} element;

#define MEMORY_SIZE 100 // memory의 크기
#define MAX_STACKS 10 // 가능한 스택의 최대수 + 1
// 전역적 메모리 선언
element memory[MEMORY_SIZE];
int top[MAX_STACKS];
int boundary[MAX_STACKS];
int n; // 사용자가 입력한 스택의 수

top[0] = boundary[0] = -1;
for (j = 1; j < n; j++)
    top[j] = boundary[j] = (MEMORY_SIZE/n) * j;
boundary[n] = MEMORY_SIZE - 1;


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

void push(int i, element item)
{ // item을 i번째 스택에 삽입
    if (top[i] == boundary[i+1])
        stackFull(i);
    memory[++top[i]] = item;
}

element pop(int i)
{ // i번째 스택에서 top원소를 제거
    if (top[i] == boundary[i])
        return stackEmpty(i);
    return memory[top[i]--];
}
