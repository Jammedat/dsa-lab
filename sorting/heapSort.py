import time
import random

def maxHeapify(A,i,n):
    l=2*i
    r=2*i+1
    largest = i
    if l<=n and A[l]>A[largest]:
        largest = l
    if r<=n and A[r]>A[largest]:
        largest = r
    if largest != i:
        A[i],A[largest] = A[largest],A[i]
        maxHeapify(A,largest,n)

def buildMaxHeap(A,n):
    for i in range(n//2,0,-1):
        maxHeapify(A,i,n)
        
def heapSort(A,n):
    buildMaxHeap(A,n)
    for i in range(n,1,-1):
        A[1],A[i] = A[i],A[1]
        n -= 1
        maxHeapify(A,1,n)
        
A = [random.randint(1,1000) for i in range(20)]
print("Original Array: ",A)
n = len(A)
A = [0]+A
start = time.time()
heapSort(A,n)
end = time.time()
diff = end-start
print("Sorted Array: ",A[1:])
print("Time taken: ",diff)

