//
//  main.c
//  polynomials_Circular
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
#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y)) ? 0 : 1)
#define TRUE -1
#define FALSE 0

typedef struct polyNode{
    int coef;
    int expon;
    struct polyNode * link;
} polyNode;

typedef polyNode * polyPointer;

polyPointer avail = NULL; // 해방된 노드들의 리스트에서 첫 번쨰 노드를 가리키는 포인터

polyPointer getNode(void);
polyPointer cpadd(polyPointer a, polyPointer b);
void attach(float coefficient, int exponent, polyNode **ptr);

int main(void) {

    return 0;
}

polyPointer getNode(void)
{ // 사용할 노드를 제공
    polyPointer node;
    if (avail)
    {
        node = avail;
        avail = avail->link;
    }
    else
        MALLOC(node, sizeof(*node));
    return node;
}

void retNode(polyPointer node)
{ // 가용 리스트에 노드를 반환
    node->link = avail;
    avail = node;
}

void cerase(polyPointer *ptr)
{ // ptr가 가리키는 원형 리스트를 제거
    polyPointer temp;
    if (*ptr)
    {
        temp = (*ptr)->link;
        (*ptr)->link = avail;
        avail = temp;
        *ptr = NULL;
    }
}

polyPointer cpadd(polyPointer a, polyPointer b)
{ // 다항식 a와 b는 헤더 노드를 가진 단순 연결 원형 리스트이고, a와 b가 합산된 다항식을 반환한다.
    polyPointer startA, c, lastC;
    int sum, done = FALSE;
    startA = a; // record start of a
    a = a->link; // skip header node for a and b
    b = b->link;
    c = getNode(); // get a header node for sum
    c->expon = -1;
    lastC = c;
    do
    {
        switch (COMPARE (a->expon, b->expon)){
            case -1: // a->expon < b->expon
                attach(b->coef, b->expon, &lastC);
                b = b->link;
                break;
            case 0: // a->expon = b->expon
                if (startA == a)
                    done = TRUE;
                else
                {
                    sum = a->coef + b->coef;
                    if (sum)
                        attach(sum, a->expon, &lastC);
                    a = a->link;
                    b = b->link;
                }
                break;
            case 1: // a->expon > b->expon
                attach(a->coef, a->expon, &lastC);
                a = a->link;
        }
    } while (!done);
    lastC->link = c;
    return c;
}

void attach(float coefficient, int exponent, polyNode **ptr)
{ // coef = coefficient이고 expon = exponent인 새로운 노드를 생성하고, 그것을 ptr에 의해 참조되는 노드에 첨가한다. ptr을 갱신하여 이 새로운 노드를 참조하도록 한다.
    polyNode *temp;
    MALLOC(temp, sizeof(*temp));
    temp->coef = coefficient;
    temp->expon = exponent;
    (*ptr)->link = temp;
    *ptr = temp;
}
