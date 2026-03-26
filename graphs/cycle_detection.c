#include <stdio.h>

int visited[100];

// DFS for cycle detection
int dfs(int graph[10][10], int n, int node, int parent) {
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(graph[node][i]) {
            if(!visited[i]) {
                if(dfs(graph, n, i, node))
                    return 1;
            }
            else if(i != parent) {
                return 1; // cycle found
            }
        }
    }
    return 0;
}

int main() {
    int n = 4;

    int graph[10][10] = {
        {0,1,0,0},
        {1,0,1,1},
        {0,1,0,0},
        {0,1,0,0}
    };

    if(dfs(graph, n, 0, -1))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}
