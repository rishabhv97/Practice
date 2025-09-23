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

// Delete from beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    printf("Deleted node from beginning with data: %d\n", temp->data);
    free(temp);
    return head;
}

// Delete from end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->next == NULL) { // Only one node
        printf("Deleted node from end with data: %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) { // Traverse till 2nd last node
        temp = temp->next;
    }
    printf("Deleted node from end with data: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

int main() {
    struct Node *head = NULL, *temp = NULL, *last = NULL;
    int n, data, i;
    char choice;

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

    // Ask user choice
    printf("\nDo you want to delete from Beginning (B) or End (E)? ");
    scanf(" %c", &choice);

    if (choice == 'B' || choice == 'b') {
        head = deleteFromBeginning(head);
    } else if (choice == 'E' || choice == 'e') {
        head = deleteFromEnd(head);
    } else {
        printf("Invalid choice.\n");
    }

    printf("\nLinked list after deletion:\n");
    printList(head);

    // Free memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
