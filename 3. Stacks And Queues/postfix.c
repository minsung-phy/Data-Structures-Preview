//
//  main.c
//  postfix
//
//  Created by 이민성 on 2023/07/27.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 // maximum stack size
#define MAX_EXPR_SIZE 100 // max size of expression

typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;

int stack[MAX_STACK_SIZE]; // global stack
char expr[MAX_EXPR_SIZE]; // input string

int top = -1;

int eval(void);
precedence getToken(char *symbol, int *n);
void push(int item);
void stackFull(void);
int pop(void);
int stackEmpty(void);

int main(void) {
    sprintf(expr, "62/3-42*+"); // sprintf(str, "문자열"); // str에 문자열 저장
    printf("expr: %s\n", expr);
    printf("eval: %d\n", eval());
    return 0;
}

int eval(void) // 후위 표기식을 계산하는 함수
{ // 전역 변수로 되어 있는 후위 표기식 expr을 연산한다. '\0'은 수식의 끝을 나타낸다. stack과 top은 전역 변수이다. 함수 gettoken은 토큰의 타입과 문자 심벌을 반환한다. 피연산자는 한 문자로 된 숫자임을 가정한다.
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0; // 수식 스트링을 위한 카운터
    token = getToken(&symbol, &n);
    while (token != eos)
    {
        if (token == operand)
            push(symbol-'0'); // 스택 삽입 (char이지만 아스키 코드를 통해 뺀 값을 구할 수 있음, 즉 아스키코드를 통해 정수값을 구하는 과정임)
        else
        { // 두 피연산자를 삭제하여 연산을 수행한 후, 그 결과를 스택에 삽입함
            op2 = pop(); // 스택 삭제
            op1 = pop();
            switch(token)
            {
                case plus: push(op1 + op2);
                    break;
                case minus: push(op1 - op2);
                    break;
                case times: push(op1 * op2);
                    break;
                case divide: push(op1 / op2);
                    break;
                case mod: push(op1 % op2);
            }
        }
        token = getToken(&symbol, &n);
    }
    return pop(); // 결과를 반환
}

precedence getToken(char *symbol, int *n) // 입력 스트링으로부터 토큰을 가져오는 함수
{ // 다음 토큰을 취한다. symbol은 문자 표현이며, token은 그것의 열거된 값으로 표현되고, 함수이름으로 반환된다.
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
        default: return operand; // 에러 검사는 하지 않고 기본 값은 피연산자
    }
}

void push(int item)
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

int pop(void)
{ // stack의 최상위 원소를 삭제하고 반환
    if (top == -1)
        return stackEmpty(); // returns an error key
    return stack[top--];
}

int stackEmpty(void)
{
    return -1;
}
