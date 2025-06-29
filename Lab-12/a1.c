// Write a program to copy a linked list.

// WAP to check whether 2 singly linked lists are same or not.

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

void display(struct Node* head) {

    struct Node* curr = head;

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

void insertAtFront(struct Node* head, int x) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->next = head;
    head = newNode;

}

struct Node* insertAtEnd(struct Node* head, int x) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = x;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return head;
    }

    struct Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
    return head;

}

void deleteheadNode(struct Node* head) {

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    head = (head) -> next;
    free(temp);

}

void deleteLastNode(struct Node* head) {

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if ((head) -> next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    curr->next = NULL;
    free(curr->next);

}

void copy(struct Node* head1, struct Node* head2){

    struct Node* curr = head1;
    struct Node* curr2 = head2;

    while(curr != NULL){

        curr2->info = curr->info;

        if (curr->next != NULL) {
            curr2->next = (struct Node*)malloc(sizeof(struct Node));
        } else {
            curr2->next = NULL;
        }
        curr = curr->next;
        curr2 = curr2->next;
    }
}

void main(){

    // struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n1 = NULL;
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));

    n1 = insertAtEnd(n1, 1);
    n1 = insertAtEnd(n1, 3);
    n1 = insertAtEnd(n1, 5);
    n1 = insertAtEnd(n1, 7);
    n1 = insertAtEnd(n1, 9);
    display(n1);

    copy(n1,n2);

    display(n2);
}

