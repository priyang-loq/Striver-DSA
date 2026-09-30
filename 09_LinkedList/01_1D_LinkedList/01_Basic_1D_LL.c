#include <stdio.h>
#include <stdlib.h>

// Definition of a Singly Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to convert an array into a 1D Linked List
struct Node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Function to traverse and print the Linked List
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to get the length of the Linked List
int getLength(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to search for an element in the Linked List
int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Element found
        }
        current = current->next;
    }
    return 0; // Element not found
}

// Function to free allocated memory
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== Basic 1D Linked List Operations ===\n\n");

    // 1. Constructing the linked list from an array
    struct Node* head = arrayToLinkedList(arr, n);

    // 2. Traversal
    printf("Linked List: ");
    printList(head);

    // 3. Length of Linked List
    printf("Length of Linked List: %d\n", getLength(head));

    // 4. Searching an element
    int target = 30;
    if (search(head, target)) {
        printf("Element %d is present in the list.\n", target);
    } else {
        printf("Element %d is not present in the list.\n", target);
    }

    target = 99;
    if (search(head, target)) {
        printf("Element %d is present in the list.\n", target);
    } else {
        printf("Element %d is not present in the list.\n", target);
    }

    // 5. Clean up memory
    freeList(head);
    head = NULL;

    return 0;
}

