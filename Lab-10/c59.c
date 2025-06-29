// WAP to check whether 2 singly linked lists are same or not.

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

void display(struct Node* *head) {

    struct Node* curr = *head;

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

void insertAtFront(struct Node* *head, int x) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->next = *head;
    *head = newNode;

}

void insertAtEnd(struct Node* *head, int x) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = x;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;

}

void deleteheadNode(struct Node* *head) {

    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head) -> next;
    free(temp);

}

void deleteLastNode(struct Node* *head) {

    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if ((*head) -> next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* curr = *head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    curr->next = NULL;
    free(curr->next);

}

void main(){

    // struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    display(&head);

    struct Node* curr = head;

    while(curr->next != NULL){

        if(curr->info == curr->next->info){

            struct Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
            continue;
        }
        else{
            curr = curr->next;
        }
    }
    display(&head);

}

