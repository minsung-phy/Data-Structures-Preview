//
//  main.c
//  queue_array
//
//  Created by 이민성 on 2023/07/26.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // 큐의 최대 크기
#define INVALID_KEY -1

typedef struct {
    int key;
    // 다른 필드
} element;

element queue[MAX_QUEUE_SIZE];

int rear = -1;
int front = -1;

void addq(element item);
element deleteq(void);
void queueFull(void);
element queueEmpty(void);

int main(void)
{
    int i;
    element e;
    for (i = 0; i < 8; i++)
    {
        e.key = i;
        addq(e);
        printf("key %2d inserted into the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
    }
    for (i = 0; i < 8; i++)
    {
        e = deleteq();
        printf("key %2d deleted from the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
    }
    for (i = 8; i < 16; i++)
    {
        e.key = i;
        addq(e);
        printf("key %2d inserted into the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
    }
    for (i = 8; i < 16; i++)
    {
        e = deleteq();
        printf("key %2d deleted from the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
    }
    return 0;
}

void addq(element item)
{ // queue에 item을 삽입
    if (rear == MAX_QUEUE_SIZE-1)
        queueFull();
    queue[++rear] = item;
}

void queueFull(void)
{
    int i, offset;
    if (front == -1)
    {
        fprintf(stderr, "no more space in the queue\n");
        exit(1);
    }
    offset = front + 1;
    for (i = front+1; i < MAX_QUEUE_SIZE; i++)
    {
        queue[i-offset] = queue[i];
    }
    front = front - offset;
    rear = rear - offset;
    printf(" ==== queue reorganized. (front: %2d rear: %2d) ====\n", front, rear);
    
    /* queue를 { , , , d, e, f, g}라 가정 (front: 2, rear: 6)
       h 삽입: offset = front + 1 = 3
       for (i = 3; i < MAX_QUEUE_SIZE; i++)
            queue[3-3] = queue[3]
            queue[4-3] = queue[4]
                    ......
     -> for(i = 8; i < 16; i++)의 경우 queuefull의 마지막 문장에서 front와 rear이 변경되어 addq의 queue[++rear]로 넘어가서 queue가 채워진다.
     */
}

element deleteq(void)
{ // queue의 앞에 있는 원소를 삭제
    if (front == rear)
        return queueEmpty(); // return an error key
    return queue[++front];
}

element queueEmpty(void)
{
    element e;
    e.key = INVALID_KEY;
    return e;
}

