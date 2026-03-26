#include <stdio.h>
#define INF 9999

int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index;

    for(int i = 0; i < n; i++) {
        if(!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[10][10], int n, int start) {
    int dist[10], visited[10];

    for(int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for(int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for(int v = 0; v < n; v++) {
            if(!visited[v] && graph[u][v] &&
               dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance\n");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int n = 4;

    int graph[10][10] = {
        {0,1,4,0},
        {1,0,2,5},
        {4,2,0,1},
        {0,5,1,0}
    };

    dijkstra(graph, n, 0);
    return 0;
}
