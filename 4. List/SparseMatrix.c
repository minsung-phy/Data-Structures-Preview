//
//  main.c
//  SparseMatrix
//
//  Created by 이민성 on 2023/08/03.
//

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
if (!( (p) = malloc(s) )) \
    { \
    fprintf(stderr, "Insufficient memory"); \
    exit(EXIT_FAILURE); \
    }

#define MAX_SIZE 50 // 최대 행렬 크기

typedef enum {head, entry} tagfield;

typedef struct {
    int row;
    int col;
    int value;
} entryNode;

typedef struct {
    struct matrixNode * down;
    struct matrixNode * right;
    tagfield tag;
    union {
        struct matrixNode * next; // head
        entryNode entry; // entry
    } u;
} matrixNode;

typedef matrixNode * matrixPointer;

matrixPointer hdnode[MAX_SIZE];

matrixPointer mread(void);
void mwrite(matrixPointer node);

int main(void) {

    return 0;
}

matrixPointer mread(void)
{ // 행렬을 읽어 연결 표현으로 구성한다. 전역 보조 배열 hdnode가 사용된다.
    int numRows, numCols, numTerms, numHeads, i;
    int row, col, value, currentRow;
    matrixPointer temp, last, node;
    
    printf("Enter the number of rows, columns and number of nonzero terms: ");
    scanf("%d%d%d", &numRows, &numCols, &numTerms);
    numHeads = (numCols > numRows) ? numCols: numRows;
    // 헤더 노드 리스트에 대한 헤더 노드를 생성한다
    node = newNode();
    node->tag = entry;
    node->u.entry.row = numRows;
    node->u.entry.col = numCols;
    
    if (!numHeads)
        node->right = node;
    else { // 헤더 노드들을 초기화한다.
        for (i = 0; i < numHeads; i++) {
            temp = newNode();
            hdNode[i] = temp;
            hdNode[i]->tag = head;
            hdnode[i]->right = temp;
            hdnode[i]->u.next = temp;
        }
        currentRow = 0;
        last = hdnode[0]; // 현재 행의 마지막 노드
        for (i = 0; i < numTerms; i++) {
            printf("Enter row, column and value: ");
            scanf("%d%d%d", &row, &col, &value);
            if (row > currentRow) { // 현재 행을 종료함
                last->right = hdnode[currentRow];
                currentRow = row;
                last = hdnode[row];
            }
            MALLOC(temp, sizeof(*temp));
            temp->tag = entry;
            temp->u.entry.row = row;
            temp->u.entry.col = col;
            temp->u.entry.value = value;
            last->right = temp; // 행 리스트에 연결
            last = temp;
            // 열 리스트에 연결
            hdnode[col]->u.next->down = temp;
            hdnode[col]->u.next = temp;
        }
        // 마지막 행을 종료함
        last->right = hdnode[currentRow];
        // 모든 열 리스트를 종료함
        for (i = 0; i < numCols; i++)
            hdnode[i]->u.next->down = hdnode[i];
        // 모든 헤더 노드들을 연결함
        for (i = 0; i < numHeads-1; i++)
            hdnode[i]->u.next = hdnode[i+1];
        hdnode[numHeads-1]->u.next = node;
        node->right = hdnode[0];
    }
    return node;
}

void mwrite(matrixPointer node)
{ // 행렬을 행 우선으로 출력한다.
    int i;
    matrixPointer temp, head = node->right;
    // 행렬의 차원
    printf("\n numRows = %d, numCols = %d \n", node->u.entry.row, node->u.entry.col);
    printf(" The matrix by row, column, and value: \n\n");
    for (i = 0; i < node->u.entry.row; i++) {
        // 각 행에 있는 엔트리들을 출력
        for (temp = head->right; temp != head; temp = temp->right)
            printf("%5d%5d%5d \n", temp->u.entry.row, temp->u.entry.col, temp->u.entry.value);
        head = head->u.next; // 다음 행
    }
}

void merase(matrixPointer *node)
{ // 행렬을 삭제하고, 노드들을 히프로 반환한다.
    matrixPointer x, y, head = (*node)->right;
    int i, numHeads;
    // 엔트리 노드와 헤더 노드들을 행 우선으로 반환한다.
    for (i = 0; i < (*node)->u.entry.row; i++) {
        y = head->right;
        while (y != head) {
            x = y;
            y = y->right;
            free(x);
        }
        x = head;
        head = head->u.next;
        free(x);
    }
    // 나머지 헤더 노드들을 반환한다.
    y = head;
    while (y != *node) {
        x = y;
        y = y->u.next;
        free(x);
    }
    free(*node);
    *node = NULL;
}
