// Write a program to swap two consecutive nodes in the linked list

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

