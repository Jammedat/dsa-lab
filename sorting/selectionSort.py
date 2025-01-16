import time
import random

def selectionSort(A,n):
    for i in range(n):
        least = A[i]
        POS = i
        for j in range(i+1,n):
            if A[j]<least:
                least = A[j]
                POS = j
        if POS != i:
            A[i],A[POS] = A[POS],A[i]
            
    return A

A = [random.randint(1,100) for i in range(10)]
print("Original Array: ",A)
n = len(A)
start = time.time()
selectionSort(A,n)
end = time.time()
diff = end-start
print("Sorted Array: ",A)
print("Time taken: ",diff)