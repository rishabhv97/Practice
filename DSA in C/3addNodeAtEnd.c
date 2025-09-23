#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to add node at the end
void addAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;  // Traverse to last node
    }
    temp->next = newNode;  // Link new node at the end
}

int main() {
    // Create initial node
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    head->data = 5;  // Existing node data
    head->next = NULL;

    printf("Original linked list:\n");
    printList(head);

    // Ask user for data to add at end
    int newData;
    printf("Enter data to add at the end: ");
    scanf("%d", &newData);

    addAtEnd(head, newData);

    printf("Updated linked list:\n");
    printList(head);

    // Free memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
