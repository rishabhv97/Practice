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

// Function to add node at beginning
void addAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
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

    // Ask user for data to add at beginning
    int newData;
    printf("Enter data to add at the beginning: ");
    scanf("%d", &newData);

    addAtBeginning(&head, newData);

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
