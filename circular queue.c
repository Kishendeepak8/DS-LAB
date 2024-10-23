#include <stdio.h>
#define MAX 4

void insert(int queue[], int *front, int *rear, int value) {
    if ((*rear + 1) % MAX == *front) {
        printf("Queue Overflow\n");
        return;
    }
    if (*front == -1) {
        *front = 0;
    }
    *rear = (*rear + 1) % MAX;
    queue[*rear] = value;
    printf("%d inserted into the queue\n", value);
}

void delete(int queue[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d deleted from the queue\n", queue[*front]);
    if (*front == *rear) {
        *front = *rear = -1;
    } else {
        *front = (*front + 1) % MAX;
    }
}

void display(int queue[], int front, int rear) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            insert(queue, &front, &rear, value);
        }
        else if (choice == 2) {
            delete(queue, &front, &rear);
        }
        else if (choice == 3) {
            display(queue, front, rear);
        }
    }

    return 0;
}
