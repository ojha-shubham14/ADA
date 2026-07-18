#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 10000
void merge(int a[],int l, int m, int h){
    int n1 = m-l+1;
    int n2 = h-m;
    int left[n1] , right[n2];
    for(int i = 0; i<n1;i++){
        left[i]=a[l+i];
    }
    for(int j = 0; j<n2;j++){
        right[j]=a[m+1+j];
    }
    int i = 0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            a[k]=left[i];
            i++;
        }
        else{
            a[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=right[j];
        j++;
        k++;
    }
}
void mergesort(int a[],int l,int h){
    int m;
    if(l<h){
        m = (l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}
int main(){
    srand(time(NULL));
    int n,a[max];
    printf("\nEnter number of elements :\n");
    scanf("%d",&n);

    printf("enter array :\n");
    for(int i=0;i<n;i++){
        a[i]=rand()%500;
        printf("%d,",a[i]);
    }
    clock_t start = clock();
    mergesort(a,0,n-1);
    clock_t stop = clock();

    printf("\nThe sorted array is :\n");
    for(int i=0;i<n;i++){
        printf("%d,",a[i]);
    }

    double time = ((double)(stop-start))/CLOCKS_PER_SEC*1000;

    printf("\nThe elapsed time in ms is : %f",time);
    return 0;
}