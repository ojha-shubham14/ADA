#include<stdio.h>
void prim(int n, int a[10][10]){
    int sum,min,source;
    int t[10][2],p[10],d[10],v[10];
    int k,u,vv,i,j;
    //Finding source vertex
    min =999,source=0;
    for(i =0;i<n;i++){
        for(j =0;j<n;j++){
            if(a[i][j]!= 0 && a[i][j]<min ){
                min = a[i][j];
                source = i;
            }
        }
    }
    //initializing
    for(i = 0;i<n;i++){
        d[i]=a[source][i];
        p[i]=source;
        v[i]=0;
    }
    v[source]=1;

    //main loop
    k = 0;
    sum=0;
    for(i=1;i<n;i++){
        min =999;
        u=-1;
        for(j=0;j<n;j++){
            if(v[j]==0){
                if(d[j]<min){
                    min = d[j];
                    u=j;
                }
            }
        }
        if(u==-1) return;

        t[k][0]=u;
        t[k][1]=p[u];
        k++;
        sum+=a[u][p[u]];
        v[u]=1;

        for(vv=0;vv<n;vv++){
            if(v[vv]==0 && a[u][vv]<d[vv]){
                d[vv]=a[u][vv];
                p[vv]=u;
            }

        }
        
    }
    if(sum>9999){
            printf("MST doesn't exists \n");
        }
        else{
            printf("MST exists \n");
            for(i=0;i<n-1;i++){
                printf("%d-->%d \n",t[i][0],t[i][1]);
            }
        }
}
void main(){
    int n;
    int a[10][10];
    printf("enter the the number of nodes \n");
    scanf("%d",&n);
    printf("Enter the cost matrix \n");
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            scanf("%d",& a[i][j]);
        }
    }
    prim(n,a);
}