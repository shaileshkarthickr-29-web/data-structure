#include <stdio.h>

#define MAX 100

int cq[MAX];
int front = -1;
int rear = -1;

int isFull() {
    if (front == 0 && rear == MAX - 1) return 1;
    if (front == rear + 1) return 1;
    return 0;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue full\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    cq[rear] = x;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    printf("Removed: %d\n", cq[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    printf("Front element: %d\n", cq[front]);
}

void display() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n\n");
        printf("Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
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
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}