#include <stdio.h>

int queue[100], front = -1, rear = -1;
int visited[100];

void enqueue(int x) {
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void bfs(int graph[10][10], int n, int start) {
    enqueue(start);
    visited[start] = 1;

    while(front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for(int i = 0; i < n; i++) {
            if(graph[node][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
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

    bfs(graph, n, 0);
    return 0;
}
