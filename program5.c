#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void heapify(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    int temp;

    if(l<n && a[l]>a[largest])
        largest=l;

    if(r<n && a[r]>a[largest])
        largest=r;

    if(largest!=i){
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;

        heapify(a,n,largest);
    }
}

void heapsort(int a[],int n){
    int i,temp;

    for(i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    for(i=n-1;i>0;i--){
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;

        heapify(a,i,0);
    }
}

int main(){
    int n,i;
    clock_t start,end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int a[n];

    srand(time(0));

    for(i=0;i<n;i++)
        a[i]=rand()%1000;

    start=clock();

    heapsort(a,n);

    end=clock();

    time_taken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Sorted elements are:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nTime taken = %f seconds\n",time_taken);

    return 0;
}