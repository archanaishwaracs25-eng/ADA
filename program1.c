#include <stdio.h>

#define MAX 20

int main() {

    int n, adj[MAX][MAX];
    int indegree[MAX] = {0};
    int visited[MAX] = {0};
    int topo[MAX];
    int i, j, count = 0, k = 0, found;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    while(count < n) {

        found = 0;

        for(i = 0; i < n; i++) {

            if(indegree[i] == 0 && visited[i] == 0) {

                topo[k++] = i;

                visited[i] = 1;
                count++;
                found = 1;

                for(j = 0; j < n; j++) {
                    if(adj[i][j] == 1) {
                        indegree[j]--;
                    }
                }
            }
        }

        if(found == 0) {
            break;
        }
    }

    if(count != n) {
        printf("Cycle detected. Topological sorting not possible.");
    }
    else {
        printf("Topological Ordering: ");

        for(i = 0; i < k; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}