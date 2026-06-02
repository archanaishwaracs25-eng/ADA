#include<stdio.h>

#define INF 9999

int main(){
    int n,i,j,u,v,count,min,start;
    
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int cost[n][n],dist[n],visited[n];

    printf("Enter adjacency matrix:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);

            if(cost[i][j]==0 && i!=j)
                cost[i][j]=INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d",&start);

    for(i=0;i<n;i++){
        dist[i]=cost[start][i];
        visited[i]=0;
    }

    dist[start]=0;
    visited[start]=1;

    for(count=1;count<n-1;count++){
        min=INF;

        for(i=0;i<n;i++){
            if(dist[i]<min && !visited[i]){
                min=dist[i];
                u=i;
            }
        }

        visited[u]=1;

        for(v=0;v<n;v++){
            if(!visited[v] && dist[u]+cost[u][v]<dist[v]){
                dist[v]=dist[u]+cost[u][v];
            }
        }
    }

    printf("Shortest distances:\n");

    for(i=0;i<n;i++){
        printf("%d -> %d = %d\n",start,i,dist[i]);
    }

    return 0;
}