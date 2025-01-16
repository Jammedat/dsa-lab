import time
import random
def insertionSort(A,n):
    for i in range(1,n):
        temp = A[i]
        j = i-1
        while j>=0 and temp<A[j]:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = temp
    return A

A = [random.randint(1,100000) for i in range(10000)]
print("Original Array: ",A)
n = len(A)
start = time.time()
insertionSort(A,n)
end = time.time()
diff = end-start
print("Sorted Array: ",A)
print("Time taken: ",diff)