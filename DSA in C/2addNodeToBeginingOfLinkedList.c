#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to add node at the beginning
void addAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;  // Link new node to current head
    *head = newNode;        // Update head
}

int main() {
    struct Node *head = NULL, *temp = NULL, *last = NULL;
    int n, data, i;

    // Create linked list
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        temp = (struct Node*)malloc(sizeof(struct Node));
        if (temp == NULL) {
            printf("Memory not allocated.\n");
            return 1;
        }
        temp->data = data;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    printf("\nOriginal linked list:\n");
    printList(head);

    // Add a node at the beginning
    printf("\nEnter data to add at the beginning: ");
    scanf("%d", &data);
    addAtBeginning(&head, data);

    printf("Linked list after adding at beginning:\n");
    printList(head);

    // Free memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
