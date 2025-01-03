#Tower of Hanoi in Python

def toh(n, src, dst, tmp):
    if n == 1:
        print("Move disc " + str(n) + " from " + src + " to " + dst)
    else:
        toh(n-1, src, tmp, dst) 
        print("Move disc " + str(n) + " from " + src + " to " + dst)
        toh(n-1, tmp, dst, src)  

num = int(input("Enter number of disks: "))
print("The sequence will be:")
toh(num, 'A', 'C', 'B')
