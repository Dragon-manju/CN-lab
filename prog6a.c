#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000
#define INF INT_MAX

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

void bellmanFord(int graph[MAX_VERTICES][3], int vertices, int edges, int source) {
    int distance[MAX_VERTICES];
    for (int i = 0; i < vertices; ++i)
        distance[i] = INF;
    distance[source] = 0;

    for (int i = 0; i < vertices - 1; ++i) {
        for (int j = 0; j < edges; ++j) {
            if (graph[j][0] != -1
                && distance[graph[j][0]] != INF
                && distance[graph[j][1]] > distance[graph[j][0]] + graph[j][2]) {
                distance[graph[j][1]] = distance[graph[j][0]] + graph[j][2];
            }
        }
    }

    for (int i = 0; i < edges; ++i) {
        if (graph[i][0] != -1 && distance[graph[i][0]] != INF
            && distance[graph[i][1]] > distance[graph[i][0]] + graph[i][2]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < vertices; ++i) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}

int main() {
    int vertices, edges, source;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    int graph[MAX_VERTICES][3];
    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    bellmanFord(graph, vertices, edges, source);

    return 0;
}
