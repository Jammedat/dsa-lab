import time
import random

def partition(A,l,r):
    x=l
    y=r
    pivot = A[l]
    while x < y:
        while A[x] <= pivot and x <= r:
            x += 1
        while A[y] > pivot and y>l:
            y -= 1
        if x < y:
            A[x],A[y] = A[y],A[x]
    A[l],A[y] = A[y],A[l]
    return y

def quickSort(A,l,r):
    if l < r:
        p = partition(A,l,r)
        quickSort(A,l,p-1)
        quickSort(A,p+1,r)
    

A = [random.randint(1,100000) for i in range(23)]
print("Original Array: ",A)
n = len(A)
start = time.time()
quickSort(A,0,n-1)
end = time.time()
diff = end-start
print("Sorted Array: ",A)
print("Time taken: ",diff)


 