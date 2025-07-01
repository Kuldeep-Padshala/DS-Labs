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

struct Node* swapFun(struct Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    struct Node* curr = head;
    struct Node* prev = NULL;
    //  struct Node* temp = curr->next->next;

    //     curr->next->next = curr;
    //     head = curr->next;
    //     curr->next = temp;

    //     curr = temp;

    while(curr!=NULL && curr -> next != NULL){

        struct Node* temp = curr->next->next;
        curr->next->next = curr;

        if(prev!=NULL){
            prev->next = curr->next;
        }
        else{
            head = curr->next;
        }
        curr->next = temp;
        prev = curr;
        curr = temp;
    }
    
    return head;

}

void main(){

    // struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head = NULL;

    head = insertAtEnd(head, 9);
    head = insertAtEnd(head, 11);
    head = insertAtEnd(head, 13);
    head = insertAtEnd(head, 15);
    head = insertAtEnd(head, 17);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 5);
    // head = insertAtEnd(head, 7);
    display(head);

    head = swapFun(head);

    display(head);
}

