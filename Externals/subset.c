#include<stdio.h>
#include<stdlib.h>
int count;
void subset(int cs,int k,int r, int x[],int w[],int d, int n){
    x[k]=1;
    if(cs+w[k] == d){
        count++;
        printf("the solution %d is {",count);
        for(int i =1;i<=k;i++){
            if(x[i]==1){
                printf("%d,",w[i]);
            }
        }
        printf("}\n");
    }
    else if((k<n)&&((cs+w[k]+w[k+1])<=d)){
        subset(cs+w[k],k+1,r-w[k],x,w,d,n);
    }
    if((k<n)&&((cs+r-w[k])>=d)&&((cs+w[k+1])<=d)){
            x[k]=0;
            subset(cs,k+1,r-w[k],x,w,d,n);
    }
    x[k]=0;
}
int main(){
    int w[100];
    int x[100];
    int sum = 0;
    int d;
    int n;
    printf("enter the number of items :\n");
    scanf("%d",&n);
    printf("\nEnter the target sum :\n");
    scanf("%d",&d);
    printf("\nEnter the weights in increasing order\n");
    for(int i=1;i<=n;i++){
        printf("item%d: ",i);
        scanf("%d",&w[i]);
        x[i]=0;
    }
    for(int i =1;i<=n;i++){
        sum+=w[i];
    }
    if(d<w[1] || sum<d){
        printf("\nthe solution is not possible as its not making up to the find sum\n");
        return 0;
    }
    subset(0,1,sum,x,w,d,n);
    if(count==0){
        printf("\nNo solution found for this in the set !!!!\n");
    }

}