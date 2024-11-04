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

void bellmanFord(Edge edges[], int vertices, int edgesCount, int source) {
    int distance[MAX_VERTICES];
    for (int i = 0; i < vertices; ++i)
        distance[i] = INF;
    distance[source] = 0;

    for (int i = 0; i < vertices - 1; ++i) {
        for (int j = 0; j < edgesCount; ++j) {
            if (distance[edges[j].source] != INF &&
                distance[edges[j].destination] > distance[edges[j].source] + edges[j].weight) {
                distance[edges[j].destination] = distance[edges[j].source] + edges[j].weight;
            }
        }
    }

    for (int i = 0; i < edgesCount; ++i) {
        if (distance[edges[i].source] != INF &&
            distance[edges[i].destination] > distance[edges[i].source] + edges[i].weight) {
            printf("Negative cycle detected\n");
            return;
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < vertices; ++i)
        printf("%d \t\t %d\n", i, distance[i]);
}

int main() {
    int vertices = 6;
    int edgesCount = 8;

    Edge graph[] = {
        {0, 1, 5},
        {0, 2, 7},
        {1, 2, 3},
        {1, 3, 4},
        {1, 4, 6},
        {3, 4, -1},
        {3, 5, 2},
        {4, 5, -3}
    };

    bellmanFord(graph, vertices, edgesCount, 0);
    return 0;
}
