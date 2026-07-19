#include<stdio.h>
#include<stdlib.h>
int min(int a , int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
void floyd(int a[10][10],int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]= min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}

void warshall(int n , int a[10][10], int r[10][10]){
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=n;j++){
            r[i][j]= a[i][j];
        }
    }

    for(int k = 1; k<= n; k++){
        for(int i =1 ; i<=n;i++){
            for(int j =1 ; j<=n;j++){
                r[i][j] = r[i][j]||r[i][k] && r[k][j];
            }
        }
    }
}

int main (){
    int a[10][10],r[10][10],b[10][10],n;
    printf("Enter the number nodes: ");
    scanf("%d",&n);
    printf("\nThe adjacency matrix for Floyd is : \n");

    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe adjacency matrix for Warshall is : \n");

    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            scanf("%d",&b[i][j]);
        }
    }

    printf("\nthe adjancy matrix for Floyds is :\n");
    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    printf("\nthe adjancy matrix for Warshall is :\n");
    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }


    printf("\nFloyds Output :\n");
    floyd(a,n);
    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\nWarshalls Output : \n");
    warshall(n,b,r);
    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            printf("%d\t",r[i][j]);
        }
        printf("\n");
    }
    return 0;
}