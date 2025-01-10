#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int A[],int l,int m,int r)
{
    int i,j,k,B[100000];
    i=l;
    j=m;
    k=l;
    while(i<m && j<=r)
    {
        if(A[i]<A[j])
        {
            B[k++]=A[i++];
        }
        else
        {
            B[k++]=A[j++];
        }
    }
    for(;i<m;i++,k++)
    {
        B[k]=A[i];
    }
    for(;j<=r;j++,k++)
    {
        B[k]=A[j];
    }
    for(k=l;k<=r;k++)
    {
        A[k]=B[k];
    }


}
void mergeSort(int A[],int l,int r)
{
    int m;
    if(l<r)
    {
        m=(l+r)/2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,r);
        merge(A,l,m+1,r);
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
    mergeSort(A,0,n);
    end=clock();
    display(A,n);
    diff=end-start;
    printf("Time Taken is %f second\n",(float)diff/CLOCKS_PER_SEC);
    return 0;
}
