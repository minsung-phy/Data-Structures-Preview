//
//  main.c
//  tree
//
//  Created by 이민성 on 2023/08/07.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100
#define MALLOC(p,s) \
if (!( (p) = malloc(s) )) \
    { \
    fprintf(stderr, "Insufficient memory"); \
    exit(EXIT_FAILURE); \
    }

typedef struct node {
    int data;
    struct node * leftChild, * rightChild;
} node;

typedef struct node * treePointer;

void inorder(treePointer ptr);
void preorder1(treePointer ptr);
void postorder1(treePointer ptr);
void iterInorder(treePointer node);
void push(treePointer item);
void stackFull(void);
treePointer pop(void);
treePointer stackEmpty(void);
void leverOder(treePointer ptr);
void addq(treePointer item);
void queueFull(void);
treePointer deleteq(void);
treePointer queueEmpty(void);
treePointer copy(treePointer original);

int top = -1;
treePointer stack[MAX_STACK_SIZE];
int front, rear = 0;
treePointer queue[MAX_QUEUE_SIZE];

int main(void) {

    return 0;
}

void inorder(treePointer ptr)
{ // 중위 트리 순회
    if (ptr) {
        inorder(ptr->leftChild);
        printf("%d", ptr->data);
        inorder(ptr->rightChild);
    }
}

void preorder1(treePointer ptr)
{ // 전위 트리 순회
    if (ptr) {
        printf("%d", ptr->data);
        preorder1(ptr->leftChild);
        preorder1(ptr->rightChild);
    }
}

void postorder1(treePointer ptr)
{ // 후위 트리 순회
    if (ptr) {
        postorder1(ptr->leftChild);
        postorder1(ptr->rightChild);
        printf("%d", ptr->data);
    }
}

void iterInorder(treePointer node)
{
    int top = -1; // 스택 초기화
    treePointer stack[MAX_STACK_SIZE];
    for (;;) {
        for (; node; node = node->leftChild)
            push(node); // 스택에 삽입
        node = pop(); // 스택에서 삭제
        if (!node) // 공백 스택
            break;
        printf("%d", node->data);
        node = node->rightChild;
    }
}

void push(treePointer item)
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

treePointer pop(void)
{ // stack의 최상위 원소를 삭제하고 반환
    if (top == -1)
        return stackEmpty(); // returns an error key
    return stack[top--];
}

treePointer stackEmpty(void)
{
    return NULL;
}

void leverOder(treePointer ptr)
{ // 레벨 순서 트리 순회
    int front, rear = 0;
    treePointer queue[MAX_QUEUE_SIZE];
    if (!ptr) // 공백 트리
        return;
    addq(ptr);
    for(;;) {
        ptr = deleteq();
        if (ptr) {
            printf("%d", ptr->data);
            if (ptr->leftChild)
                addq(ptr->rightChild);
            if (ptr->rightChild)
                addq(ptr->rightChild);
        }
        else break;
    }
}

void addq(treePointer item)
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
}

treePointer deleteq(void)
{ // queue의 앞에 있는 원소를 삭제
    if (front == rear)
        return queueEmpty(); // return an error key
    return queue[++front];
}

treePointer queueEmpty(void)
{
    return NULL;
}

treePointer copy(treePointer original)
{ // 주어진 트리를 복사하고 복사된 트리의 treePointer를 반환한다
    treePointer temp;
    if (original) {
        MALLOC(temp, sizeof(*temp));
        temp->leftChild = copy(original->leftChild);
        temp->rightChild = copy(original->rightChild);
        temp->data = original->data;
        return temp;
    }
    return NULL;
}

int equal(treePointer first, treePointer second)
{ // 두 이진 트리가 동일하면 TRUE, 그렇지 않으면 FASLE를 반환한다
    return ( (!first && !second) || (first && second && (first->data == second->data) && equal(first->leftChild, second->leftChild) && equal(first->rightChild, second->rightChild)));
}
