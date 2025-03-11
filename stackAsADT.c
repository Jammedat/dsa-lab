#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the user-defined structure
typedef struct {
    char name[50];
    int age;
} Person;

// Define the stack structure
typedef struct {
    Person* items;
    int top;
    int capacity;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (Person*)malloc(stack->capacity * sizeof(Person));
    return stack;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an item to the stack
void push(Stack* stack, Person item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push item.\n");
        return;
    }
    stack->items[++stack->top] = item;
    printf("Pushed: %s, %d\n", item.name, item.age);
}

// Function to pop an item from the stack
Person pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop item.\n");
        Person emptyPerson = {"", -1};
        return emptyPerson;
    }
    return stack->items[stack->top--];
}

// Function to peek at the top item of the stack
Person peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No item to peek.\n");
        Person emptyPerson = {"", -1};
        return emptyPerson;
    }
    return stack->items[stack->top];
}

// Function to display the stack
void displayStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%s, %d\n", stack->items[i].name, stack->items[i].age);
    }
}

// Function to free the stack
void freeStack(Stack* stack) {
    free(stack->items);
    free(stack);
}

int main() {
    // Create a stack with a capacity of 5
    Stack* stack = createStack(5);

    // Create some Person objects
    Person p1 = {"Ram", 25};
    Person p2 = {"Hari", 30};
    Person p3 = {"Krishna", 35};

    // Push the Person objects onto the stack
    push(stack, p1);
    push(stack, p2);
    push(stack, p3);

    // Display the stack
    displayStack(stack);

    // Peek at the top item
    Person topPerson = peek(stack);
    printf("Top of the stack: %s, %d\n", topPerson.name, topPerson.age);

    // Pop an item from the stack
    Person poppedPerson = pop(stack);
    printf("Popped: %s, %d\n", poppedPerson.name, poppedPerson.age);

    // Display the stack again
    displayStack(stack);

    // Free the stack
    freeStack(stack);

    return 0;
}