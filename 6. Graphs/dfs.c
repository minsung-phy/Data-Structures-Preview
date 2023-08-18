//
//  main.c
//  dfs
//
//  Created by 이민성 on 2023/08/18.
//

#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define MAX_VERTIVES 50

short int visited[MAX_VERTIVES];

void dfs(int v)
{ // depth first search of a graph beginning at V
    nodePointer w;
    visited[v] = TRUE;
    printf("%5d", v);
    for (w = graph[v]; w; w = w->link)
        if (!visited[w->vertex])
            dfs(w->vertex);
}

int main() {
    
    return 0;
}


