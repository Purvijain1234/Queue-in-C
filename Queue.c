#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

int queue[MAX], front = -1, rear = -1;

// Function to enqueue an element into the queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) front = 0;  // Set front for the first element
        queue[++rear] = value;
        printf("%d enqueued into queue\n", value);
    }
}

// Function to dequeue an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot dequeue\n");
    } else {
        printf("%d dequeued from queue\n", queue[front++]);
        if (front > rear) front = rear = -1;  // Reset queue when empty
    }
}

// Function to peek at the front element
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

// Function to display the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
