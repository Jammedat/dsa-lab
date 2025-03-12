def evaluate_prefix(prefix_exp):
    tokens = prefix_exp.split()
    stack = []
    operators = {"^", "/", "*", "+", "-"}
    
   
    for token in reversed(tokens):
        if token not in operators: 
            stack.append(float(token))
        else: 
            op1 = stack.pop()
            op2 = stack.pop()
            
            if token == '+':
                result = op1 + op2
            elif token == '-':
                result = op1 - op2
            elif token == '*':
                result = op1 * op2
            elif token == '/':
                result = op1 / op2
            elif token == '^':
                result = op1 ** op2
            
            stack.append(result) 

    return stack[0]  

inp = input("Enter a prefix expression: ")
result = evaluate_prefix(inp)
print(f"Result is {result}")
