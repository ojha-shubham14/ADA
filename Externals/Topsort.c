#include <stdio.h>
#include <stdio.h>
#define max 100
int stack[max];
int top = -1;
int adj [max][max];
int visited[max];
void dfs(int v ){
    visited[v]=1;
    for(int i =0;i<max;i++){
        if(adj[v][i]&& !visited[i]){
            dfs(i);
        }
    }
    stack[++top]=v;
}
void topsort(int v){
    for(int i = 0;i<v;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    printf("\n top sort order:");
    while(top!=-1){
        printf("%d",stack[top--]);
    }
    printf("\n");
}
void main(){
    int n;
    printf("enter the number of nodes in the graph :\n");
    scanf("%d",&n);
    printf("enter the adjaceny matrix :\n");
    for(int i = 0; i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    topsort(n);
}