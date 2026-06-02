#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quicksort(int a[],int low,int high){
    int i,j,pivot,temp;
    if(low<high){
        pivot=a[low];
        i=low;
        j=high;

        while(i<j){
            while(a[i]<=pivot&&i<high)
                i++;
            while(a[j]>pivot)
                j--;

            if(i<j){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }

        temp=a[low];
        a[low]=a[j];
        a[j]=temp;

        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
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

    quicksort(a,0,n-1);

    end=clock();

    time_taken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Sorted elements are:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nTime taken = %f seconds\n",time_taken);

    return 0;
}