#include<stdio.h>

int dfs(int v, int parent);
int n, a[10][10], vis[10];
int cycle_detected = 0;

int main() {
    int i, j, connected = 1;

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }


    dfs(1, -1);

    for(i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            connected = 0;
            break;
        }
    }

    if(connected)
        printf("The graph is connected.\n");
    else
        printf("The graph is not connected.\n");

    if(cycle_detected)
        printf("The graph contains a cycle.\n");
    else
        printf("The graph does not contain a cycle.\n");

    return 0;
}

int dfs(int v, int parent) {
    vis[v] = 1;

    for(int j = 1; j <= n; j++) {
        if(a[v][j] == 1) {
            if(vis[j] == 0) {
                if(dfs(j, v))
                    return 1;
            } else if(j != parent) {
                cycle_detected = 1;
                return 1;
            }
        }
    }
    return 0;
}
