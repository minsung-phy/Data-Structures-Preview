//
//  main.c
//  LinkedList2
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

// typedef struct listNode *listPointer;
struct listNode{
    int data;
    struct listNode *link;
};

struct listNode *first = NULL;
struct listNode *second;

struct listNode * create2(void)
{ // 2개의 노드를 가진 연결 리스트의 생성
    MALLOC(first, sizeof(*first));
    MALLOC(second, sizeof(*second));
    second->link = NULL;
    second->data = 20;
    first->data = 10;
    first->link = second;
    return first;
}

void insert(struct listNode **first, struct listNode *x)
{ // data = 50인 새로운 노드를 체인
  // first의 노드 x 뒤에 삽입
    struct listNode * temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = 50;
    if (*first)
    {
        temp->link = x->link;
        x->link = temp;
    }
    else
    {
        temp->link = NULL;
        *first = temp;
    }
}

void delete(struct listNode **first, struct listNode *trail, struct listNode *x)
{ // 리스트로부터 노드를 삭제, trail은 삭제될 x의 선행 노드이며 first는 리스트의 시작
    if (trail)
        trail->link = x->link;
    else
        *first = (*first)->link;
    free(x);
}

void printList(struct listNode *first)
{
    printf("The list contains: ");
    for (; first; first = first->link)
        printf("%4d", first->data);
    printf("\n");
}

int main(void) {
    
    return 0;
}
