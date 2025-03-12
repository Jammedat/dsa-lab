#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5 // Maximum size of the circular queue

// Define the structure for the circular queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// Function to create an empty circular queue
CircularQueue* createCircularQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
bool isFull(CircularQueue* queue) {
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->rear) == (queue->front - 1) % (MAX_SIZE - 1);
}

// Function to check if the queue is empty
bool isEmpty(CircularQueue* queue) {
    return queue->front == -1;
}

// Function to add an element to the queue (enqueue)
void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->rear == MAX_SIZE - 1 && queue->front != 0) {
        queue->rear = 0; // Wrap around
    } else {
        queue->rear++;
    }

    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value = queue->items[queue->front];
    if (queue->front == queue->rear) {
        // Queue has only one element, reset the queue
        queue->front = -1;
        queue->rear = -1;
    } else if (queue->front == MAX_SIZE - 1) {
        queue->front = 0; // Wrap around
    } else {
        queue->front++;
    }

    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the circular queue
void displayQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");
    if (queue->rear >= queue->front) {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
    } else {
        for (int i = queue->front; i < MAX_SIZE; i++) {
            printf("%d ", queue->items[i]);
        }
        for (int i = 0; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
    }
    printf("\n");
}

// Function to free the circular queue
void freeCircularQueue(CircularQueue* queue) {
    free(queue);
}

int main() {
    // Create a circular queue
    CircularQueue* queue = createCircularQueue();

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50); // Queue is now full

    // Try to enqueue when the queue is full
    enqueue(queue, 60); // Should print "Queue is full."

    // Display the queue
    displayQueue(queue);

    // Dequeue elements
    dequeue(queue);
    dequeue(queue);

    // Display the queue after dequeue
    displayQueue(queue);

    // Enqueue more elements (wrap around)
    enqueue(queue, 60);
    enqueue(queue, 70);

    // Display the queue after wrap-around enqueue
    displayQueue(queue);

    // Free the queue
    freeCircularQueue(queue);

    return 0;
}