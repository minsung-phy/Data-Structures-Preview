//
//  main.c
//  ShortestPaths
//
//  Created by 이민성 on 2023/08/23.
//

#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0

void shortestPath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]);
int choose(int distance[], int n, short int found[]);
void allCosts(int cost[][MAX_VERTICES], int distance[][MAX_VERTICES], int n);

int main(void) {
    return 0;
}

void shortestPath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]) // 하나의 출발점에서 최단 경로
{ // distance[i] represents the shortest path from vertex v to i, found[i] is 0 if the shortest path from i has not been found and a 1 if it has, cost is the adjacenct matrix
    int i, u, w;
    for (i = 0; i < n; i++) { // 초기
        found[i] = FALSE;
        distance[i] = cost[v][i]; // i까지의 최단거리, 초기에는 source부터 i까지의 거리이다. (직접 연결 할 수 있는 경우 값이 존재하고, 없으면 값이 존재하지 않는다. 이는 cost에서 정의한다.)
    }
    found[v] = TRUE;
    distance[v] = 0;
    for (i = 0; i < n-2; i++) {
        u = choose(distance, n, found); // 시작 정점 v로부터 최소 거리를 갖는 정점 u를 반환
        found[u] = TRUE;
        for (w = 0; w < n; w++) // 가장 짧은 거리를 구함
            if (!found[w])
                if (distance[u] + cost[u][w] < distance[w])
                    distance[w] = distance[u] + cost[u][w];
    }
}

int choose(int distance[], int n, short int found[])
{ // find the smallest distance not yet checked (아직까지 found가 안된 vertex 중 distance 값이 가장 작은 것을 선택)
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i = 0; i < n; i++)
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    return minpos;
}

//void BellmanFord(int n, int v)
//{ // 음의 길이 간선을 가지는 단일 시발점 모든 종점의 최단 경로
//    for (int i = 0; i < n; i++)
//        dist[i] = length[v][i]; // initialize dist
//
//    for (int k = 2; k <= n-1; k++)
//        for (each u such that u != v and u has at leant one incoming edge)
//            for (each <i, u> in the graph)
//                if (dist[u] > dist[i] + length[i][u])
//                    dist[u] = dist[i] + length[i][u];
//}

void allCosts(int cost[][MAX_VERTICES], int distance[][MAX_VERTICES], int n) // 모든 쌍의 최단 경로를 구하는 함수
{ // compute the shortest distance from each vertex to every other, cost is the adjacency matrix, distance is the matrix of computed distances.
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            distance[i][j] = cost[i][j];
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
}

void transtiveClosure(int cost[][MAX_VERTICES], int distance[][MAX_VERTICES], int n) // 이행적 폐쇄
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            distance[i][j] = cost[i][j];
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                distance[i][j] = distance[i][j] || (distance[i][k] && distance[k][j]);
}
