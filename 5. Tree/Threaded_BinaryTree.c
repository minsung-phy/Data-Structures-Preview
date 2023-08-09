//
//  main.c
//  Threaded_BinaryTree
//
//  Created by 이민성 on 2023/08/09.
//

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct threadedTree * threadedPointer;

typedef struct threadedTree {
    short int leftThread;
    threadedPointer leftChild;
    char data;
    threadedPointer rightChild;
    short int rightThread;
} threadedTree;

threadedPointer insucc(threadedPointer tree);
void tinorder(threadedPointer tree);

int main(void) {
    return 0;
}

threadedPointer insucc(threadedPointer tree)
{ // 스레드 이진 트리에서 중위 후속자를 찾는다
    threadedPointer temp;
    temp = tree->rightChild;
    if (!tree->rightThread)
        while (!temp->leftThread)
            temp = temp->leftChild;
    return temp;
}

void tinorder(threadedPointer tree)
{ // 스레드 이진 트리의 중위 순회
    threadedPointer temp = tree;
    for(;;) {
        temp = insucc(temp);
        if (temp == tree)
            break;
        printf("%3c", temp->data);
    }
    
}

void insertRight(threadedPointer s, threadedPointer r)
{ // 스레드 이진 트리에서 r을 s의 오른쪽 자식으로 삽입
    threadedPointer temp;
    r->rightChild = parent->rightChild;
    r->rightThread = parent->rightThread;
    r->leftChild = parent;
    r->leftThread = TRUE;
    s->rightChild = child;
    s->rightThread = FALSE;
    if (!r->rightThread) {
        temp = insucc(r);
        temp->leftChild = r;
    }
}
