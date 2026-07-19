#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 10000
int partition(int a[],int low , int high){
    int pivot=a[low];
    int start = low;
    int end = high;
    while(start<end){
        while(a[start]<= pivot){
            start++;
        }
        while(a[end]>pivot){
            end --;
        }
        if(start<end){
            int temp = a[start];
            a[start]= a[end];
            a[end]= temp;
        }
    }
    int temp= a[low];
    a[low]=a[end];
    a[end]=temp;
    return end;
}

void quickSort(int a[],int low, int high){
    if(low<high){
        int pivotIndex = partition(a,low,high);
        quickSort(a,low,pivotIndex-1);
        quickSort(a,pivotIndex+1,high);
    }
}

int main(){
    srand(time(NULL));
    int a[max];
    int n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d",&n);
    printf("\nThe array is :\n");
    for(int i =0;i<n;i++){
        a[i]=rand()%300;
        printf("%d,",a[i]);
    }
    clock_t start = clock();
    quickSort(a,0,n-1);
    clock_t stop = clock();
    
    double time = ((double)(stop-start))/CLOCKS_PER_SEC*1000;

    printf("\nsorted array is : \n");
    for(int i=0;i<n;i++){printf("%d,",a[i]);}

    printf("\nTime elapased to sort in ms is :%f",time);
    return 0;
}