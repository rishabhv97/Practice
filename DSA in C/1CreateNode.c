#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

// Define the structure for a node and create an alias 'Node'
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Check if malloc was successful
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }

    // Initialize the new node
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int main() {
    // Create a pointer for our first node (often called the 'head' of a list)
    Node* head;

    // Use our function to create a node with data value 10
    head = createNode(10);

    // Check if the node was created successfully before using it
    if (head != NULL) {
        // Print the data from the node to confirm it works
        printf("Node created successfully!\n");
        printf("Data in the node: %d\n", head->data); // Access data using the -> operator
    }

    // IMPORTANT: Free the allocated memory when you're done with it
    free(head);
    head = NULL; // Good practice to avoid dangling pointers

    return 0;
}