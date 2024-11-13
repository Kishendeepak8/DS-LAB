#include <stdio.h>

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

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    if (head == NULL) return;

    struct Node* i = head;
    struct Node* j;
    int temp;
    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concatenateLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, data;

    printf("Enter number of elements for list 1: ");
    scanf("%d", &n);
    printf("Enter the elements for list 1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&list1, data);
    }

    printf("Enter number of elements for list 2: ");
    scanf("%d", &n);
    printf("Enter the elements for list 2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&list2, data);
    }

    printf("Original list 1:\n");
    printList(list1);

    sortList(list1);
    printf("Sorted list 1:\n");
    printList(list1);

    reverseList(&list1);
    printf("Reversed list 1:\n");
    printList(list1);

    printf("Original list 2:\n");
    printList(list2);

    concatenateLists(&list1, list2);
    printf("Concatenated list:\n");
    printList(list1);

    return 0;
}