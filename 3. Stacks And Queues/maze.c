//
//  main.c
//  maze
//
//  Created by 이민성 on 2023/07/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_STACK_SIZE 100 // 스택의 최대 크기
#define MAX_ROW 13
#define MAX_COL 17
#define EXIT_ROW 11
#define EXIT_COL 15

int maze[MAX_ROW][MAX_COL];
int mark[MAX_ROW][MAX_COL];

typedef struct {
    short int vert;
    short int horiz;
} offsets;
offsets moving[8]; // 각 방향에 대한 이동 배열

typedef struct {
    short int row;
    short int col;
    short int dir;
} element;
element stack[MAX_STACK_SIZE];

int top = -1; // if top is -1, it means the stack is empty

void push(element);
void stackFull(void);
element pop(void);
element stackEmpty(void);
void path(void);

int main(void) {
    int i, j;
    
    int maze_values[MAX_ROW][MAX_COL] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1}, {1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1}, {1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1}, {1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1}, {1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1}, {1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1}, {1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1}, {1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1}, {1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1}, {1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1}, {1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
    
    memcpy(maze, maze_values, sizeof(int) * MAX_ROW * MAX_COL);
    
    // initialize mark
    for (i = 0; i < MAX_ROW; i++)
    {
        for (j = 0; j < MAX_COL; j++)
        {
            mark[i][j] = 0;
        }
    }
    
    // initialize moving
    moving[0].vert = -1; moving[0].horiz = 0; // N
    moving[1].vert = -1; moving[1].horiz = 1; // NE
    moving[2].vert = 0; moving[2].horiz = 1; // E
    moving[3].vert = 1; moving[3].horiz = 1; // SE
    moving[4].vert = 1; moving[4].horiz = 0; // S
    moving[5].vert = 1; moving[5].horiz = -1; // SW
    moving[6].vert = 0; moving[6].horiz = -1; // W
    moving[7].vert = -1; moving[7].horiz = -1; // NW
    
    // run path algorithm
    path();
    
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
    stack[0].dir = 2;
    while (top > -1 && !found)
    {
        position = pop();
        row = position.row;
        col = position.col;
        dir = position.dir;
        while (dir < 8 && !found)
        { // dir 방향으로 이동
            nextRow = row + moving[dir].vert;
            nextCol = col + moving[dir].horiz;
            if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
                found = TRUE;
            else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
            {
                mark[nextRow][nextCol] = 1;
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
            printf("%2d%5d\n ", stack[i].row, stack[i].col);
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
        stackEmpty(); // returns an error key
    return stack[top--];
}

element stackEmpty(void)
{
    fprintf(stderr, "Stack is full, cannot add element");
    exit(EXIT_FAILURE);
}
