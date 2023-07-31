//
//  main.c
//  queue
//
//  Created by 이민성 on 2023/07/31.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUES 10 // 큐의 최대 수
#define INVALID_KEY -1
#define MALLOC(p,s) \
if (!( (p) = malloc(s) )) \
    { \
    fprintf(stderr, "Insufficient memory"); \
    exit(EXIT_FAILURE); \
    }

typedef struct {
    int key;
    // 기타 필드
} element;

    
struct queue{
    element data;
    struct queue * link;
};

struct queue * front[MAX_QUEUES], * rear[MAX_QUEUES];

void addq(int i, element item);
element deleteq(int i);
element queueEmpty(void);

int main(void) {
    return 0;
} 

void addq(int i, element item)
{ // 큐 i의 뒤에 원소를 삽입
    struct queue * temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = item;
    temp->link = NULL;
    if (front[i])
        rear[i]->link = temp;
    else
        front[i] = temp;
    rear[i] = temp;
}

element deleteq(int i)
{ // 큐 i로부터 원소를 삭제
    struct queue * temp = front[i];
    element item;
    if (!temp)
        return queueEmpty();
    item = temp->data;
    front[i] = temp->link;
    free(temp);
    return item;
}

element queueEmpty(void)
{
    element e;
    e.key = INVALID_KEY;
    return e;
}
