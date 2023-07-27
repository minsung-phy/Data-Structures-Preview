//
//  main.c
//  infix_to_postfix
//
//  Created by 이민성 on 2023/07/27.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;

precedence stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

/* isp와 icp 배열 -- 인덱스는 연산자
   lparen, rparen, plus, minus, times, divide, mod, eos의 우선순위 값 */
static precedence isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
static precedence icp[] = {20, 19, 12, 12, 13, 13, 13, 0};


void postfix(void);
precedence getToken(char *symbol, int *n);
void printToken(precedence token);
void push(precedence item);
void stackFull(void);
precedence pop(void);
precedence stackEmpty(void);

int main(void) {
    sprintf(expr, "6/2-3+4*2");
    printf("infix   : %s\n", expr);
    printf("postfix : ");
    postfix();
    return 0;
}

void postfix(void)
{ // 수식을 후위 표기식으로 출력한다. 수식 스트링, 스택, top은 전역적이다.
    char symbol;
    precedence token; // 토큰의 수
    int n = 0;
    top = 0; // eos를 스택에 삽입한다 (끝을 알기 위해서)
    stack[0] = eos;
    for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
    {
        if (token == operand)
            printf("%c", symbol);
        else if (token == rparen)
        { // 왼쪽 괄호가 나올 때까지 토큰들을 제거해서 출력시킴
            while (stack[top] != lparen)
                printToken(pop());
            pop(); // 왼쪽 괄호를 버린다
        }
        else
        { // symbol의 isp가 token의 icp보다 크거나 같으면 symbol을 제거하고 출력시킴
            while (isp[stack[top]] >= isp[token]) // stack의 top에 있는 것 >= 들어올 것
                // stkck의 top에 있는 것이 들어올 것의 우선순위보다 높으면 stack에서 top에 있는 것을 뽑아서 print한다.
                printToken(pop());
            push(token);
        }
    }
    while ((token = pop()) != eos)
         printToken(token);
    printf("\n");
}

precedence getToken(char *symbol, int *n)
{
    *symbol = expr[(*n)++];
    switch(*symbol)
    {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '/': return divide;
        case '*': return times;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}

void printToken(precedence token)
{
    switch(token)
    {
        case lparen: printf("("); break;
        case rparen: printf(")"); break;
        case plus: printf("+"); break;
        case minus: printf("-"); break;
        case divide: printf("/"); break;
        case times: printf("*"); break;
        case mod: printf("%%"); break;
    }
}

void push(precedence item)
{
    if (top >= MAX_STACK_SIZE - 1)
        stackFull();
    stack[++top] = item;
}

void stackFull(void)
{
    fprintf(stderr, "Stack is full, cannot add element");
    exit(EXIT_FAILURE);
}

precedence pop(void)
{ // stack의 최상위 원소를 삭제하고 반환
    if (top == -1)
        return stackEmpty(); // returns an error key
    return stack[top--];
}

precedence stackEmpty(void)
{
    return -1;
}

