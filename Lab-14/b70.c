// WAP to split a circular linked list into two halves

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node* splitCircularList(struct Node* head) {

    if (head == NULL || head->next == head) {
        return NULL;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = slow->next;
    slow->next = head;

    struct Node* curr = secondHalf;
    while (curr->next != head) {
        curr = curr->next;
    }
    curr->next = secondHalf;

    return secondHalf;
}

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
    struct Node* prev = NULL;

    if (position == 0) {
        // Deleting the head node
        if (curr->next == *head) { // Only one node in the list
            free(curr);
            *head = NULL;
            return;
        } else {
            while (curr->next != *head) {
                curr = curr->next;
            }
            curr->next = (*head)->next; // Update last node's next to new head
            free(*head);
            *head = curr->next; // Update head to next node
            return;
        }
    }

    for (int i = 0; i < position && curr->next != *head; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == *head || curr->next == *head) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = curr->next; // Bypass the node to be deleted
    free(curr);
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
}


void main(){

    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    printf("Original Circular Linked List:\n");
    display(head->next);

    struct Node* secondHalf = splitCircularList(head);

    printf("First Half:\n");
    display(head);
    
    printf("Second Half:\n");
    display(secondHalf);

    printf("First Half:\n");
    display(head);
    
    printf("Second Half:\n");
    display(secondHalf);

}

