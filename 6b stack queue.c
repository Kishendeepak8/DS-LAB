#include <stdio.h>
#include <stdlib.h>
1
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top_ref, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top_ref;
    *top_ref = newNode;
    printf("Pushed %d to stack\n", data);
}

int pop(struct Node** top_ref) {
    if (*top_ref == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top_ref;
    int popped_data = temp->data;
    *top_ref = temp->next;
    free(temp);
    return popped_data;
}

void displayStack(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}


void enqueue(struct Node** front_ref, struct Node** rear_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*rear_ref == NULL) {
        *front_ref = *rear_ref = newNode;
    } else {
        (*rear_ref)->next = newNode;
        *rear_ref = newNode;
    }
    printf("Enqueued %d to queue\n", data);
}

int dequeue(struct Node** front_ref) {
    if (*front_ref == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node* temp = *front_ref;
    int dequeued_data = temp->data;
    *front_ref = temp->next;
    if (*front_ref == NULL) {
        *rear_ref = NULL;
    }
    free(temp);
    return dequeued_data;
}


void displayQueue(struct Node* front) {
    printf("Queue: ");
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stackTop = NULL; 
    struct Node* queueFront = NULL; 
    struct Node* queueRear = NULL; 

    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);
    displayStack(stackTop);
    printf("Popped from stack: %d\n", pop(&stackTop));
    displayStack(stackTop);

    
    enqueue(&queueFront, &queueRear, 1);
    enqueue(&queueFront, &queueRear, 2);
    enqueue(&queueFront, &queueRear, 3);
    displayQueue(queueFront);
    printf("Dequeued from queue: %d\n", dequeue(&queueFront));
    displayQueue(queueFront);

    return 0;
}