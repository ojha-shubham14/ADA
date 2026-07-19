#include<stdio.h>
#include<stdlib.h>
int main(){
    float total=0,r[50],temp;
    float w[50],p[50],capacity;
    int i,j,n;
    printf("enter the total item :\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the weight and profit of the item %d\n",i);
        scanf("%f%f",&w[i],&p[i]);
    }
    printf("\n");
    for(i=0;i<n;i++){
        r[i]=(p[i]/w[i]);
    }
    printf("\n");
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(r[i]<r[j]){
                temp = r[j];r[j]=r[i];r[i]=temp;
                temp = p[j];p[j]=p[i];p[i]=temp;
                temp = w[j];w[j]=w[i];w[i]=temp;
            }
        }
    }
    printf("\n");
    printf("\n Enter the capacity of the knapsack:");
    scanf("%f",&capacity);
    printf("knapsack using Greedy Technique\n");
    for(i=0;i<n;i++){
        if(w[i]>capacity){
            break;
        }
        else{
            total+=p[i];
            capacity-=w[i];
        }
    }
    if(i<n){
        total+=r[i]*capacity;
    }
    printf("\nThe maximum profit using Greedy Technique in knapsack is :%f",total);
    return 0;
}