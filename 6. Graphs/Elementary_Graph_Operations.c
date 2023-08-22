//
//  main.c
//  Elementary_Graph_Operations
//
//  Created by 이민성 on 2023/08/21.
//

#include <stdio.h>



#define FALSE 0
#define TRUE 1
#define MAX_VERTIVES 50
#define MIN2 (x, y) ((x) < (y) ? (x) : (y))

short int visited[MAX_VERTIVES];
short int dfn[MAX_VERTIVES];
short int low[MAX_VERTIVES];
int num;

typedef struct queue *queuePointer;
typedef struct {
    int vertex;
    queuePointer link;
} queue;
queuePointer front, rear;

void addq(int);
int deleteq();

void dfs(int v);
void bfs(int v);
void connected(void);

int main(void) {
    return 0;
}

void dfs(int v)
{ // depth first search of a graph beginning at V
    nodePointer w;
    visited[v] = TRUE;
    printf("%5d", v);
    for (w = graph[v]; w; w = w->link)
        if (!visited[w->vertex])
            dfs(w->vertex);
}

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

void connected(void)
{ // determine the connected components of a graph
    int i;
    for (i = 0; i < n; i++)
        if (!visited[i]) {
            dfs(i);
            printf("\n");
        }
}

void dfnlow(int u, int v)
{ // compare dfn and low while performing a dfs search beginning at vertex u, v is the parent of u (if any)
    nodePointer ptr;
    int w;
    dfn[u] = low[u] = num++;
    for (ptr = graph[u]; ptr; ptr = ptr->link) {
        w = ptr->vertex;
        if (dfn[w] < 0) { // w is an unvisited vertex
            dfnlow(w, u);
            low[u] = MIN2(low[u], low[w]);
        }
        else if ( w != v)
            low[u] = MIN2(low[u], dfn[w]);
    }
}

void init(void)
{
    int i;
    for (i = 0; i < n; i++) {
        visited[i] = FALSE;
        dfn[i] = low[i] = -1;
    }
    num = 0;
}

void bicon(int u, int v)
{ // compare dnf and low, and output the edges of G by their biconnected components, v is the parent (if any) of u in the resulting spanning tree. It is assumed that all entries of dnf[] have been initialized to -1, num is initiallu to 0, and the stack is initially empty
    nodePointer ptr;
    int w, x, y;
    dfn[u] = low[u] = num++;
    for (ptr = graph[u]; ptr; ptr = ptr->link) {
        w = ptr->vertex;
        if (v != w && dfn[w] < dfn[u])
            push(u, w); // add edge to stack
            if (dfn[w] < 0) { // w has not been visited
                bicon(w, u);
                low[u] = MIN2(low[u], low[w]);
                if (low[w] >= dfn[u]) {
                    printf("New biconnected component: ");
                    do { // delete edge from stack
                        pop(&x, &y);
                        printf(" <%d,%d>", x, y);
                    } while (!((x == u) && (y == w)));
                    printf("\n");
                }
            }
            else if (w != v)
                low [u] = MIN2(low[u], dfn[w]);
    }
}
