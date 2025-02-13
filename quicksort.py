import time
import random

def partition(A, l, r):
    x = l
    y = r
    pivot = A[l]
    while x < y:
        while A[x] <= pivot and x <= r:
            x += 1
        while A[y] > pivot and y > l:
            y -= 1
        if x < y:
            temp = A[x]
            A[x] = A[y]
            A[y] = temp
    temp = A[l]
    A[l] = A[y]
    A[y] = temp
    return y

def quickSort(A, l, r):
    if l < r:
        p = partition(A, l, r)
        quickSort(A, l, p - 1)
        quickSort(A, p + 1, r)

def display(A, n):
    for i in range(0, n):
        print(A[i], end=" ")
    print()

A = [0] * 100000
print("Enter n:", end=" ")
n = int(input())
for i in range(0, n):
    A[i] = random.randint(0, 10)
display(A, n)
start = time.time()
quickSort(A, 0, n - 1)
end = time.time()
display(A, n)
diff = end - start
print(f"Time Taken is {diff:.6f} second")
