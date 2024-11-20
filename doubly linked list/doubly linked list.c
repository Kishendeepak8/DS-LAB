#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* createDoublyLinkedList() {
    Node* head = NULL;
    Node* tail = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

void insertLeft(Node** head, int value, int newData) {
    Node* current = *head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    Node* newNode = createNode(newData);
    newNode->next = current;
    newNode->prev = current->prev;

    if (current->prev != NULL) {
        current->prev->next = newNode;
    } else {
        *head = newNode;
    }
    current->prev = newNode;
}

void deleteNode(Node** head, int value) {
    Node* current = *head;

    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Node with value %d deleted.\n", value);
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, value, newData;

    do {
        printf("\nMenu:\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Insert to the Left of a Node\n");
        printf("3. Delete a Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createDoublyLinkedList();
                break;
            case 2:
                printf("Enter the value of the node to insert to the left of: ");
                scanf("%d", &value);
                printf("Enter the new data to insert: ");
                scanf("%d", &newData);
                insertLeft(&head, value, newData);
                break;
            case 3:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
