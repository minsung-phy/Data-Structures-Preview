//
//  main.c
//  DoublyLinkedList
//
//  Created by 이민성 on 2023/08/03.
//

#include <stdio.h>

typedef struct {
    int i;
} element;

typedef struct {
    struct node * llink;
    element data;
    struct node * rlink;
} node;

typedef node * nodePointer;

int main(void) {

    return 0;
}

void dinsert(nodePointer node, nodePointer newnode)
{ // newnode를 node의 오른쪽에 삽입
    newnode->llink = node;
    newnode->rlink = node->rlink;
    node->rlink->llink = newnode;
    node->rlink = newnode;
}

void ddelete(nodePointer node, nodePointer deleted)
{ // 이중 연결 리스트에서 삭제
    if (node == deleted)
        printf("Deletion of head와 node not permitted.\n");
    else {
        deleted->llink->rlink = deleted->rlink;
        deleted->rlink->llink = deleted->llink;
        free(deleted);
    }
}
