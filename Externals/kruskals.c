#include<stdio.h>
int kruskals(int n,int cost[10][10]){
    int parent[10]={0};
    int min,mincost=0,a,b,u,v,ne=1;
    while(ne<n){
        min = 999;
        for(int i=1;i<=n;i++){
            for(int j =1;j<=n;j++){
                if(cost[i][j]<min){
                    min= cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        while(parent[u]>0){
            u=parent[u];
        }
        while(parent[v]>0){
            v=parent[v];
        }
        if(u!=v){
            printf("%d edge (%d,%d)= %d\n",ne++,a,b,min);
            parent[v]=u;
            mincost+=min;

        }
        cost[a][b]=cost[b][a]=999;
    }
    return mincost;
}
int main(){
    int cost[10][10],n;
    int mincost;
    printf("Enter total number of nodes \n");
    scanf("%d",&n);
    printf("\nEnter the cost matrix \n");
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    printf("\n");
    mincost=kruskals(n,cost);
    printf("\nMinimum cost spanning tree is :%d",mincost);
    return 0;
}