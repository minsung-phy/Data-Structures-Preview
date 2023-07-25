//
//  main.c
//  maze
//
//  Created by 이민성 on 2023/07/25.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_STACK_SIZE 100 // 스택의 최대 크기
#define INVALID_KEY -1

typedef struct {
    short int vert;
    short int horiz;
} offsets;

typedef struct {
    short int row;
    short int col;
    short int dir;
} element;

offsets moving[8]; // 각 방향에 대한 이동 배열

int top = -1; // if top is -1, it means the stack is empty

//nextRow = row + move[dir].vert;
//nextCol = col + move[dir].horiz;

void path(void);
void push(element item);
void stackFull(void);
element pop(void);
element stackEmpty(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

void path(void)
{ // 미로를 통과하는 경로가 있으면 그 경로를 출력한다.
    int i, row, col, nextRow, nextCol, dir, found=FALSE;
    element position;
    mark[1][1] = 1;
    top = 0;
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 1;
    while (top > -1 && !found)
    {
        position = pop(&top);
        row = position.row;
        col = position.col;
        dir = position.dir;
        while (dir < 8 && !found)
        { // dir 방향으로 이동
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
                found = TRUE;
            else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
            {
                mark([nextRow][nextCol]) = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;
                push(position);
                row = nextRow;
                col = nextCol;
                dir = 0;
            }
            else ++dir;
        }
    }
    if (found)
    {
        printf("The path is:\n");
        printf("row col\n");
        for (i = 0; i <= top; i++)
            printf("%2d%5d", stack[i].row, stack[i].col);
        printf("%2d%5d\n", row, col);
        printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
    }
    else printf("The maze does not have a path\n");
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
