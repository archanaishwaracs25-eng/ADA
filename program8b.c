#include<stdio.h>
#include<stdlib.h>
struct Edge{
    int u,v,w;
};
void swap(struct Edge *a,struct Edge *b){
    struct Edge t=*a;
    *a=*b;
    *b=t;
}
int parent[100];
int find(int i){
    while(parent[i]!=i)
        i=parent[i];
    return i;
}
void unionSet(int a,int b){
    parent[find(a)]=find(b);
}
int main(){
    int v,e,i,j;
    printf("Enter vertices and edges: ");
    scanf("%d%d",&v,&e);
    struct Edge edge[e];
    printf("Enter u v w:\n");
    for(i=0;i<e;i++)
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    for(i=0;i<v;i++)
        parent[i]=i;
    for(i=0;i<e-1;i++){
        for(j=0;j<e-i-1;j++){
            if(edge[j].w>edge[j+1].w)
                swap(&edge[j],&edge[j+1]);
        }
    }
    int cost=0;
    printf("Edges in MST:\n");
    for(i=0;i<e;i++){
        int a=find(edge[i].u);
        int b=find(edge[i].v);
        if(a!=b){
            printf("%d - %d : %d\n",edge[i].u,edge[i].v,edge[i].w);
            cost+=edge[i].w;
            unionSet(a,b);
        }
    }
    printf("Minimum Cost = %d",cost);
    return 0;
}