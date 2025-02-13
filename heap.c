#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}

void maxHeapify(int A[],int i,int n)
{
    int l,r,largest,temp;
    l=left(i);
    r=right(i);
    largest=i;

    if(l<=n && A[l]>A[largest])
    {
        largest=l;
    }
    if(r<=n && A[r]>A[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        maxHeapify(A,largest,n);
    }

}

void buildMaxHeap(int A[],int n)
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        maxHeapify(A,i,n);
    }
}

void HeapSort(int A[],int n)
{
    int i,temp;
    buildMaxHeap(A,n);
    for(i=n;i>=2;i--)
    {
        temp=A[i];
        A[i]=A[1];
        A[1]=temp;
        n=n-1;
       maxHeapify(A,1,n); 
    }
}

void display(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d  ",A[i]);
    }
    printf("\n");
    printf("\n");
}
int main()
{
    int A[100000],n,i;
    clock_t start,end,diff;
    srand(time(NULL));
    printf("Enter n ");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
        A[i]=rand()%1000;//rand()%10

    display(A,n);
    start=clock();
    HeapSort(A,n);
    end=clock();
    display(A,n);
    
    printf("The time Taken us %f seconds \n",(float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}