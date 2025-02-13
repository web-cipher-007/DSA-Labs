import time
import random

def selectionSort(A,n):
    for i in range(0,n):
        least=A[i]
        POS=i
        for j in range(i+1,n):
            if A[j]<least:
                least=A[j]
                POS=j
        if i!=POS:
            least=A[i]
            A[i]=A[POS]
            A[POS]=least
            
        

def display(A,n):
    for i in range(0,n):
        print(A[i],end=" ")
    print(" ")

A=[0]*100000
print("Enter n:",end=" ")
n=int(input())

for i in range(0,n):
    A[i]=random.randint(0,10)
# display(A,n)
start=time.time()
selectionSort(A,n)
end=time.time()
# display(A,n)
diff=end-start
print(f"The time taken is {diff:.6f} seconds")
