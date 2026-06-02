#include<stdio.h>

int main(){
    int n,i,j,min,u,v,total=0;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int cost[n][n],visited[n];

    printf("Enter cost adjacency matrix:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);

            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }

    for(i=0;i<n;i++)
        visited[i]=0;

    visited[0]=1;

    printf("Edges in Minimum Spanning Tree:\n");

    for(int ne=1;ne<n;ne++){
        min=999;

        for(i=0;i<n;i++){
            if(visited[i]){
                for(j=0;j<n;j++){
                    if(!visited[j] && cost[i][j]<min){
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }

        printf("%d -> %d = %d\n",u,v,min);

        total+=min;
        visited[v]=1;
    }

    printf("Minimum cost = %d",total);

    return 0;
}