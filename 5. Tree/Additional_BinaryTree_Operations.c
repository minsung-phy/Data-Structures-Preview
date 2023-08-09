//
//  main.c
//  Additional_BinaryTree_Operations
//
//  Created by 이민성 on 2023/08/08.
//

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef enum {not, and, or, true, false} logical;

typedef struct node * treePointer;

typedef struct node{
    treePointer leftChild;
    logical data;
    short int value;
    treePointer rightChild;
} node;

int main(void) {
    return 0;
}

/*
만족성 알고리즘의 첫 번째 버전
for (all 2^n possible combinations) {
    generate the next combination;
    replace the variables by their values;
    evaluate root by traversing it in postorder;
    if (root->value) {
        printf(<combination>);
        return;
    }
}
printf("No satisfiable combination\n");
*/

void postOrderEval(treePointer node)
{ // 명제 해석 트리를 계산하기 위해 수정된 후위 순회
    if (node) {
        postOrderEval(node->leftChild);
        postOrderEval(node->rightChild);
        switch(node->data) {
            case not:
                node->value = !node->rightChild->value;
                break;
            case and:
                node->value = node->rightChild->value && node->leftChild->value;
                break;
            case or:
                node->value = node->rightChild->value || node->leftChild->value;
                break;
            case true:
                node->value = TRUE;
                break;
            case false:
                node->value = FALSE;
        }
    }
}
