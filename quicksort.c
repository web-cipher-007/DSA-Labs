#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Partition(int A[],int l,int r)
{
    int X,Y,Pivot,temp;
    X=l;
    Y=r;
    Pivot=A[l];
    while(X<Y)
    {
        while (A[X]<=Pivot && X<=r)
        {
            X++;
        }
        while(A[Y]>Pivot && Y>l)
        {
            Y--;
        }
        if(X<Y)
        {
            temp=A[X];
            A[X]=A[Y];
            A[Y]=temp;
            
        }
    }
    temp=A[l];
    A[l]=A[Y];
    A[Y]=temp;
    return Y;
}
void quickSort(int A[],int l,int r)
{
    int p;
    if(l<r)
    {
        p=Partition(A,l,r);
        quickSort(A,l,p-1);
        quickSort(A,p+1,r);
    }
}

void display(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main()
{
    int A[100000],n,i;
    clock_t start,end,diff;
    printf("Enter n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }
    display(A,n);
    start =clock();
    quickSort(A,0,n-1);
    end=clock();
    display(A,n);
    diff=end-start;
    printf("Time Taken is %f second\n",(float)diff/CLOCKS_PER_SEC);
    return 0;
}
