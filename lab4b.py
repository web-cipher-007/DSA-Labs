#factorial using recursive

def fact(n):
    if (n==0):
        return 1
    else:
        return n*fact(n-1)
num=int(input("Enter the numebr you want to know the fatorial of"))
print("The factorial of " + str(num) + " is " + str(fact(num))) 