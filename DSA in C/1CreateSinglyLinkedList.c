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

int main() {
    struct Node *head = NULL, *temp = NULL, *last = NULL;
    int n, data, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    // Create n nodes
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
            head = temp;  // First node
            last = temp;
        } else {
            last->next = temp;  // Link new node
            last = temp;
        }
    }

    printf("Singly linked list created:\n");
    printList(head);

    // Free memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
