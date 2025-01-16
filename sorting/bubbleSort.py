import time
import random
def bubbleSort(A,n):
    for i in range(n-1):
        for j in range(n-i-1):
            if A[j]>A[j+1]:
                start = time.time()
                A[j],A[j+1]=A[j+1],A[j]
                end = time.time()
                
    return A

A = [random.randint(1,100000) for i in range(10000)]
print("Original Array: ",A)
n = len(A)
start = time.time()
bubbleSort(A,n)
end = time.time()
diff = end-start
print("Sorted Array: ",A)
print("Time taken: ",diff)