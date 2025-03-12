def fibonacci(n):
    if n <= 0:
        return "Invalid input"
    elif n == 1:
        return 1
    elif n == 2:
        return 1  
    return fibonacci(n - 1) + fibonacci(n - 2) 

num = int(input("Enter the term number: "))
print(f"The {num}th Fibonacci term is {fibonacci(num)}")
