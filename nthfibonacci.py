#fibonacci using recursion

def fibo(n):
    if n==1 or n==2:
        return 1
    else:
        return fibo(n-1) + fibo(n-2)
n=int(input("Enter the position:"))
print("The" + str(n) +"th Fibonacci number is" + str(fibo(n)) )
    
