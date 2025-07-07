// Write a menu driven program to implement following operations on the circular linked list.
// Insert a node at the front of the linked list.
// Delete a node from specified position.
// Insert a node at the end of the linked list.
// Display all nodes.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

void insertAtFront(struct Node** head, int x) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = x;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Point to itself
    } 
    else {
        struct Node* curr = *head;
        while (curr->next != *head) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void deleteNodeAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = *head;

    if (position == 1) {
        // Deleting the head node
        if (curr->next == *head) { // Only one node in the list
            free(curr);
            *head = NULL;
            return;
        } 
        else {
            while (curr->next != *head) {
                curr = curr->next;
            }
            curr->next = (*head)->next; // Update last node's next to new head
            free(*head);
            *head = curr->next; // Update head to next node
            return;
        }
    }

    struct Node* prev = NULL;
    curr = *head;
    for (int i = 1; i < position && curr->next != *head; i++) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == *head) {
        printf("Position out of bounds.\n");
        return;
    }

    if (curr->next == *head) {
        if (prev != NULL) {
            prev->next = *head;
        } else {
            *head = NULL;
        }
    } else {
        prev->next = curr->next;
    }


}

void insertAtEnd(struct Node** head, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = x;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Point to itself
        return;
    }

    struct Node* curr = *head;
    while (curr->next != *head) {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = *head; // New node points to head
}

void display(struct Node* head) {
    
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = head;
    printf("List: ");

    do {
        printf("%d -> ", curr->info);
        curr = curr->next;
    } while (curr != head);

    printf("....\n");
}

void main(){

    struct Node* head = NULL;
    int choice, value, position;
    printf("Menu:\n");
    printf("1. Insert at front\n");
    printf("2. Delete from specified position\n");
    printf("3. Insert at end\n");
    printf("4. Display all nodes\n");
    printf("5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtFront(&head, value);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNodeAtPosition(&head, position);
                break;
            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

}