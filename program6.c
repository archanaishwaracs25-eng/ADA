#include<stdio.h>

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int main(){
    int n,m,i,w;

    printf("Enter number of items: ");
    scanf("%d",&n);

    int wt[n],val[n];

    printf("Enter weights:\n");
    for(i=0;i<n;i++)
        scanf("%d",&wt[i]);

    printf("Enter profits:\n");
    for(i=0;i<n;i++)
        scanf("%d",&val[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d",&m);

    int K[n+1][m+1];

    for(i=0;i<=n;i++){
        for(w=0;w<=m;w++){
            if(i==0 || w==0)
                K[i][w]=0;

            else if(wt[i-1]<=w)
                K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);

            else
                K[i][w]=K[i-1][w];
        }
    }

    printf("Maximum profit = %d",K[n][m]);

    return 0;
}