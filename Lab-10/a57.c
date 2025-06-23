// Write a menu driven program to implement following operations on the singly linked list.
// Insert a node at the front of the linked list.
// Display all nodes.
// Delete a first node of the linked list.
// Insert a node at the end of the linked list.
// Delete a last node of the linked list.
// Delete a node from specified position.
// count the number of nodes

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node* first = NULL;

void display() {

    struct Node* curr = first;

    if (curr == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->info);
        curr = curr->next;
    }
    printf("NULL\n");
}

void insertAtFront(int x) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->next = first;
    first = newNode;

}

void insertAtEnd(int x) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = x;
    newNode->next = NULL;

    if (first == NULL) {
        first = newNode;
        return;
    }

    struct Node* curr = first;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;

}

void deleteFirstNode() {

    if (first == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = first;
    first = first->next;
    free(temp);

}

void deleteLastNode() {

    if (first == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (first->next == NULL) {
        free(first);
        first = NULL;
        return;
    }

    struct Node* curr = first;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    curr->next = NULL;
    free(curr->next);

}

void deleteNodeAtPosition(int pos) {

    if (first == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        deleteFirstNode();
        return;
    }

    struct Node* curr = first;

    for (int i = 1; (i < pos - 1 && curr != NULL); i++) {
        curr = curr->next;
    }
    // curr no next position chhe

    if (curr == NULL || curr->next == NULL) {
        printf("out of bounds.\n");
        return;
    }

    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);

}

int countNodes() {

    int count = 0;
    struct Node* curr = first;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    return count;
}

void main(){

    int choice, value, position;
    
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Display all nodes\n");
        printf("3. Delete first node\n");
        printf("4. Insert at end\n");
        printf("5. Delete last node\n");
        printf("6. Delete node at specified position\n");
        printf("7. Count nodes\n");
        printf("8. Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtFront(value);
                break;
            case 2:
                display();
                break;
            case 3:
                deleteFirstNode();
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 5:
                deleteLastNode();
                break;
            case 6:
                printf("Enter position to delete node: ");
                scanf("%d", &position);
                deleteNodeAtPosition(position);
                break;
            case 7:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}