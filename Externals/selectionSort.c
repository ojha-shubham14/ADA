#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 10000
void selectionSort(int a[max],int n){
    int temp,min;
    for(int i =0;i<n-1;i++){
        min=i;
        for(int j = i+1; j<n;j++){
            if(a[j]<a[min]){
                min=a[j];
            }
        }
        temp = a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}
int main(){
    int n,min,a[max];
    printf("Enter the number of elements :\n");
    scanf("%d",&n);
    printf("Enter the array :\n");
    srand(time(NULL));
    for(int i = 0;i<n;i++){
        a[i]=rand()%200;
        printf("%d,",a[i]);
    }
    clock_t start = clock();
    selectionSort(a,n);
    clock_t stop = clock();
    printf("The sorted array is : \n");
    for(int i=0;i<n;i++){
        printf("%d,",a[i]);
    }
    double elapsed = ((double)(stop - start))/CLOCKS_PER_SEC*1000;
    printf("\n\nTime taken to sort : %f",elapsed);
    return 0;
}


