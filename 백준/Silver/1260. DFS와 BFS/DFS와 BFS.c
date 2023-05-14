#include <stdio.h>

#define MAX 1001


int n, m, v, s, e;

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int l = 0, r = 0;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 1; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

void bfs(int v) {
    queue[r++] = v;
    visited[v] = 1;
    int t;
    while (1) {
        t = queue[l++];
        for (int i = 1; i < n; i++) {
            if (graph[t][i] == 1 && visited[i] == 0) {
                queue[r++] = i;
                visited[i] = 1;
            }
        }
        if (l > r) {
            break;
        }
    }
    for (int i = 0; i < r; i++) {
        printf("%d ", queue[i]);
    }
}


int main(void) {
    scanf("%d %d %d", &n, &m, &v);
    n = n + 1;

    for (int i = 1; i < n; i++) { // initialize
        visited[i] = 0;
        for (int j = 1; j < n; j++)
            graph[i][j] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        graph[s][e] = 1;
        graph[e][s] = 1;
    }

    dfs(v);
    printf("\n");
    for (int i = 1; i < n; i++) {
        visited[i] = 0;
    }
    bfs(v);
}
