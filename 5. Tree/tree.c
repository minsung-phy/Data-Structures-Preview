//
//  main.c
//  tree
//
//  Created by 이민성 on 2023/08/07.
//

#include <stdio.h>

typedef struct node {
    int data;
    struct node * leftChild, * rightChild;
} node;

typedef struct node * treePointer;

void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

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

void preorder(treePointer ptr)
{ // 전위 트리 순회
    if (ptr) {
        printf("%d", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr)
{ // 후위 트리 순회
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%d", ptr->data);
    }
}
