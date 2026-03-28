#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXQ 100

char queue[MAXQ][50];
int front = 0;
int rear = 0;

int isFull() { return (rear + 1) % MAXQ == front; }
int isEmpty() { return front == rear; }

void addDoc() {
    if (isFull()) {
        printf("Queue full\n");
        return;
    }
    printf("Enter document name: ");
    scanf("%s", queue[rear]);
    rear = (rear + 1) % MAXQ;
}

void printDoc() {
    if (isEmpty()) {
        printf("No documents pending\n");
        return;
    }
    printf("Printing: %s\n", queue[front]);
    front = (front + 1) % MAXQ;
}

void displayPending() {
    if (isEmpty()) {
        printf("No pending documents\n");
        return;
    }
    printf("Pending documents:\n");
    int i = front;
    while (i != rear) {
        printf("- %s\n", queue[i]);
        i = (i + 1) % MAXQ;
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1. Add document\n2. Print document\n3. Display pending\n4. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addDoc(); break;
            case 2: printDoc(); break;
            case 3: displayPending(); break;
            case 4: return 0;
            default: printf("Invalid\n");
        }
    }
    return 0;
}