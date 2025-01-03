#greatest common divisor or HCF
def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))
print("The GCD/HCF of " + str(num1)+ " and " + str(num2) + " is " + str(gcd(num1,num2)))
