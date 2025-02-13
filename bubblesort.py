import time
import random

def bubbleSort(A,n):
    for i in range(0,n-1):
        for j in range(0,n-1-i):
            if A[j]>A[j+1]:
                temp=A[j]
                A[j]=A[j+1]
                A[j+1]=temp

def display(A,n):
    for i in range(0,n):
        print(A[i],end=" ")
    print(" ")

A=[0]*100000
print("Enter n:",end=" ")
n=int(input())

for i in range(0,n):
    A[i]=random.randint(0,10)
display(A,n)
start=time.time()
bubbleSort(A,n)
end=time.time()
display(A,n)
diff=end-start
print(f"The time taken is {diff:.6f} seconds")