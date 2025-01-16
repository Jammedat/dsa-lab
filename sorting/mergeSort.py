import time
import random

def merge(A,l,m,r):
    B = A[:]
    i = l
    j=m
    k=l
    while i<m and j<=r:
        if A[i]<A[j]:
            B[k] = A[i]
            i += 1
        else:
            B[k] = A[j]
            j += 1
        k += 1
        
    while i<m:
        B[k] = A[i]
        i += 1
        k += 1
        
    while j<=r:
        B[k] = A[j]
        j += 1
        k += 1
    
    for i in range(l, r + 1):
        A[i] = B[i]
        
    
    
def mergeSort(A,l,r):
    if l<r:
        m = (l+r)//2
        mergeSort(A,l,m)
        mergeSort(A,m+1,r)
        merge(A,l,m+1,r)
    return A

A = [random.randint(1,100000) for i in range(10)]
print("Original Array: ",A)
n = len(A)
start = time.time()
mergeSort(A,0,n-1)
end = time.time()
diff = end-start
print("Sorted Array: ",A)
print("Time taken: ",diff)
