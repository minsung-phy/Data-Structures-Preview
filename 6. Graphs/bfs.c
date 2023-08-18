//
//  main.c
//  bfs
//
//  Created by 이민성 on 2023/08/18.
//

#include <stdio.h>

void bfs(int v);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

typedef struct queue *queuePointer;
typedef struct {
    int vertex;
    queuePointer link;
} queue;
queuePointer front, rear;
void addq(int);
int deleteq();

void bfs(int v)
{
    // breadth first traversal of a graph, starting at v global srray visited is initialized to 0, the queue operations are similar to those described in Chapter 4, front and rear are global
    nodePointer w;
    front = rear = NULL; // initialize queue
    printf("%5d", v);
    visited[v] = TRUE;
    addq(v);
    while (front) {
        v = deleteq();
        for (w = graph[v]; w; w->link)
            if (!visited[w->vertex]) {
                printf("%5d", w->vertex);
                addq(w->vertex);
                visited[w->vertex] = TRUE;
            }
    }
}
