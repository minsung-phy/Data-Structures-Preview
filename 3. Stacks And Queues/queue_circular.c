//
//  main.c
//  queue_circular
//
//  Created by 이민성 on 2023/07/26.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
#define INVALID_KEY -1

typedef struct {
    int key;
    // 다른 필드
} element;

element queue[MAX_QUEUE_SIZE];

int front = 0;
int rear = 0;

void addq(element item);
void queueFull(void);
element deleteq(void);
element queueEmpty(void);

int main(void) {
    int i;
    element e;
     for (i = 0; i < 8; i++)
    {
        e.key = i;
        addq(e);
        printf("key %2d inserted into the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
    }
    printf("\n");
    for (i = 0; i < 8; i++)
    {
        e = deleteq();
        printf("key %2d deleted from the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
    }
    printf("\n");
    for (i = 8; i < 16; i++)
    {
        e.key = i;
        addq(e);
        printf("key %2d inserted into the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
    }
    printf("\n");
    for (i = 8; i < 16; i++)
    {
        e = deleteq();
        printf("key %2d deleted from the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
    }
    return 0;
}

void addq(element item)
{ // queue에 item을 삽입
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    if (front == rear)
        queueFull(); // print error and exit
    queue[rear] = item;
}

element deleteq(void)
{ // queue의 앞 원소를 삭제
    if (front == rear)
        return queueEmpty(); // return an error key
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}

void queueFull(void)
{
    if (front == -1)
    {
        fprintf(stderr, "no more space in the queue\n");
        exit(1);
    }
}

element queueEmpty(void)
{
    element e;
    e.key = INVALID_KEY;
    return e;
}
