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

int countNodes(struct Node* head) {

    int count = 0;
    struct Node* curr = head;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    return count;
}

int getGCD(int a, int b) {
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void insertGCD(struct Node* head){

    struct Node* curr = head;
    if(curr == NULL){
        return;
    }

    while(curr->next != NULL){

        struct Node* temp = curr->next;
        int gcd = getGCD(curr->info, temp->info);
        struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));

        temp2->info = gcd;
        temp2->next = temp;
        curr->next = temp2;

        curr = curr->next->next;
    }
}

void main(){

    // struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head = NULL;

    head = insertAtEnd(head, 6);
    head = insertAtEnd(head, 12);
    head = insertAtEnd(head, 16);
    head = insertAtEnd(head, 25);
    head = insertAtEnd(head, 5);
    
    display(head);

    insertGCD(head);

    display(head);
}

