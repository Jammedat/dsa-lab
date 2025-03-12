def linear_search(arr, target):
 
    for i, value in enumerate(arr):
        if value == target:
            return i 
    return -1  

# Example usage
if __name__ == "__main__":
    arr = [4, 2, 7, 1, 9, 3, 6]  
    target = 7
    
    result = linear_search(arr, target)
    
    if result != -1:
        print(f"Element {target} found at index {result}.")
    else:
        print(f"Element {target} not found in the array.")