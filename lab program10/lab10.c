#include <stdio.h>
#include <stdlib.h>

int *ht;
int count = 0, n, m;

void insert(int key) {
    int index = key % m;
    while (ht[index] != -1) {
        index = (index + 1) % m;
    }
    ht[index] = key;
    count++;
}

void display() {
    if (count == 0) {
        printf("\nHash Table is empty");
        return;
    }

    printf("\nHash Table contents are:\n");
    for (int i = 0; i < m; i++) {
        if (ht[i] != -1)
            printf("T[%d] --> %d\n", i, ht[i]);
        else
            printf("T[%d] --> EMPTY\n", i);
    }
}

int main() {
    int *keys;

    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);

    printf("\nEnter the size of the hash table (m): ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));
    if (!ht) {
        printf("Memory allocation failed!");
        return 1;
    }
    for (int i = 0; i < m; i++) {
        ht[i] = -1;
    }

    keys = (int *)malloc(n * sizeof(int));
    if (!keys) {
        printf("Memory allocation failed!");
        free(ht);
        return 1;
    }

    printf("\nEnter the key values (K) for N Employee Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Key %d: ", i + 1);
        scanf("%d", &keys[i]);
    }

    for (int i = 0; i < n; i++) {
        if (count == m) {
            printf("\nHash table is full. Cannot insert the record for key %d", keys[i]);
            break;
        }
        insert(keys[i]);
    }

    display();


    free(ht);
    free(keys);

    return 0;
}

