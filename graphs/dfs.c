#include <stdio.h>

int visited[100];

// DFS
void dfs(int graph[10][10], int n, int node) {
    printf("%d ", node);
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(graph[node][i] == 1 && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int main() {
    int n = 4;

    int graph[10][10] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,0}
    };

    dfs(graph, n, 0);
    return 0;
}
