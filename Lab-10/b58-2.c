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

int isSameFun(struct Node* head1,struct Node* head2){

    struct Node* curr1 = head1;
    struct Node* curr2 = head2;

    int isSame = 1;

    while(curr1 != NULL && curr2 != NULL){

        if(curr1->info != curr2->info){
            isSame = 0;
            break;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    if((curr1 == NULL && curr2 != NULL) || (curr1 != NULL && curr2 == NULL)){
        printf("Both Linkedlist are not equal");
        return 0;
    }

    if(isSame){
        printf("Both Linkedlist are same");
    }
    else{
        printf("Both Linkedlist are not same");
    }
    return isSame;
}

void main(){

    // struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    head1 = insertAtEnd(head1, 1);
    head1 = insertAtEnd(head1, 3);
    head1 = insertAtEnd(head1, 5);
    head1 = insertAtEnd(head1, 7);
    head1 = insertAtEnd(head1, 9);
    display(head1);

    head2 = insertAtEnd(head2, 1);
    head2 = insertAtEnd(head2, 3);
    head2 = insertAtEnd(head2, 5);
    head2 = insertAtEnd(head2, 7);
    head2 = insertAtEnd(head2, 9);
    display(head2);

    int isSame = isSameFun(head1, head2);
}

