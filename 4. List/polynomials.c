//
//  main.c
//  polynomials
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
#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y)) ? 0 : 1)

typedef struct polyNode{
    int coef;
    int expon;
    struct polyNode *link;
} polyNode;

polyNode *a, *b;

polyNode *padd(polyNode *a, polyNode *b);
void attach(float coefficient, int exponent, polyNode **ptr);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

polyNode *padd(polyNode *a, polyNode *b)
{
    polyNode *c, *rear, *temp;
    int sum;
    MALLOC(rear, sizeof(*rear));
    c = rear;
    while (a && b)
        switch (COMPARE (a->expon, b->expon)){
            case -1: // a->expon < b->expon
                attach(b->coef, b->expon, &rear);
                b = b->link;
                break;
            case 0: // a->expon = b->expon
                sum = a->coef + b->coef;
                if (sum)
                    attach(sum, a->expon, &rear);
                a = a->link;
                b = b->link;
                break;
            case 1: // a->expon > b->expon
                attach(a->coef, a->expon, &rear);
                a = a->link;
        }
    for (; a; a = a->link)
        attach(a->coef, a->expon, &rear);
    for (; b; b = b->link)
        attach(b->coef, b->expon, &rear);
    rear->link = NULL;
    // 필요 없는 초기 노드를 삭제
    temp = c;
    c = c->link;
    free(temp);
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
