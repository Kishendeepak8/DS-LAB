i
#include <stdio.h>

void bfs(int v);
int a[10][10], vis[10], n;

void main() {
    int i, j, src;

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }

    printf("Enter the source vertex (1-based index):\n");
    scanf("%d", &src);

    printf("Nodes reachable from the source vertex:\n");
    bfs(src);
}

void bfs(int v) {
    int q[10], f = 0, r = 0, u, i;
    q[r] = v;
    vis[v] = 1;

    while(f <= r) {
        u = q[f++];

        printf("%c ", 'A' + u - 1);

        for(i = 1; i <= n; i++) {
            if(a[u][i] == 1 && vis[i] == 0) {
                vis[i] = 1;
                q[++r] = i;
            }
        }
    }
}
