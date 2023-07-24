//
//  main.c
//  matrix
//
//  Created by 이민성 on 2023/07/22.
//

#include <stdio.h>

#define MAX_TERMS 101 // 항의 최대수 + 1
#define MAX_COL 101

typedef struct {
    int col;
    int row;
    int value;
} term;

term a[MAX_TERMS];

void transpose(term a[], term b[])
{ // a를 전치시켜 b를 생성
    int n, i, j, currentb;
    n = a[0].value; // 총 원소수
    b[0].row = a[0].col; // b의 행 수 = a의 열 수
    b[0].col = a[0].row; // b의 열 수 = a의 행 수
    b[0].value = n;
    if (n > 0)
    { // 0이 아닌 행렬
        currentb = 1;
        for (i = 0; i < a[0].col; i++) // 행 별로 값을 저장하므로 a의 열별로 차례로 b로 옮긴다.
        // a에서의 열변 전치
            for (j = 1; j <= n; j++) // j는 각 원소의 인덱스를 쭉 짚어간다.
            // 현재의 열로부터 원소를 찾는다.
                if (a[j].col == i) // a의 j번째의 열 번호가 내가 하고자 하는 행 번호와 같으면
                { // 현재의 열에 있는 원소를 b에 첨가한다.
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
    }
    
}

void fastTranspose(term a[], term b[])
{ // a를 전치시켜 b에 저장
    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i, j, numCols = a[0].col, numTerms = a[0].value;
    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;
    if (numTerms > 0) {
        for (i = 0; i < numCols; i++)
            rowTerms[i] = 0; // rowTerms에 0을 넣음
        for (i = 1; i <= numTerms; i++)
            rowTerms[a[i].col]++; // 여기서 a[1].col = 0이고 row.terms[0]을 ++를 시켜줌 (그림 2.5 a행렬 참조)
                                  //      a[2].col = 3이고 row.terms[3]을 ++를 시켜줌
                                  //                    .....
                                  //                    .....
                                  // 즉, 개수를 세어주는 것임
        startingPos[0] = 1;
        for(i = 1; i < numCols; i++)
            startingPos[i] = startingPos[i-1] + rowTerms[i-1];
        for(i = 1; i <= numTerms; i++)
        {
            j = startingPos[a[i].col]++; // 밑에꺼 다하고(b를 채우고) startingPos[a[i].col]을 증가 (증가 시키면서 채우는 것을 반복)
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}
