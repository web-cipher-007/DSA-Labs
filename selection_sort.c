#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionSort(int A[],int n)
{
    int i,least,POS,j,temp;
    for(i=0;i<n;i++)
    {
        least=A[i];
        POS=i;
        for(j=0;j<n;j++)
        {
            if(A[j]<least)
            {
                least=A[j];
                POS=j;
            }
        }
    }
    if(i!=POS)
    {
        temp=A[i];
        A[i]=A[POS];
        A[POS]=temp;
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
    selectionSort(A,n);
    end=clock();
    display(A,n);
    diff=end-start;
    printf("Time Taken is %f second\n",(float)diff/CLOCKS_PER_SEC);
    return 0;
}
