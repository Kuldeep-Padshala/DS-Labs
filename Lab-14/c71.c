// Write a program to perform addition of two polynomial equations using appropriate data structure

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

    printf("NULL\n");
}

void additionOfPolynomials(struct Node* poly1, struct Node* poly2, struct Node** result) {
    
    struct Node* curr1 = poly1;
    struct Node* curr2 = poly2;

    while (curr1 != NULL || curr2 != NULL) {
        int coeff1 = (curr1 != NULL) ? curr1->info : 0;
        int coeff2 = (curr2 != NULL) ? curr2->info : 0;

        int sum = coeff1 + coeff2;
        insertAtEnd(result, sum);

        if (curr1 != NULL) curr1 = curr1->next;
        if (curr2 != NULL) curr2 = curr2->next;
    }
}

void main(){

    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Example: Polynomial 1: 3x^2 + 2x + 1
    insertAtEnd(&poly1, 3); // Coefficient of x^2
    insertAtEnd(&poly1, 2); // Coefficient of x^1
    insertAtEnd(&poly1, 1); // Coefficient of x^0

    // Example: Polynomial 2: 4x^2 + 5x + 6
    insertAtEnd(&poly2, 4); // Coefficient of x^2
    insertAtEnd(&poly2, 5); // Coefficient of x^1
    insertAtEnd(&poly2, 6); // Coefficient of x^0

    printf("Polynomial 1:\n");
    display(poly1);
    
    printf("Polynomial 2:\n");
    display(poly2);

    additionOfPolynomials(poly1, poly2, &result);

    printf("Resultant Polynomial after Addition:\n");
    display(result);

}