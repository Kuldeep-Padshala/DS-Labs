// Add a node that contains the GCD of that two nodes between every pair adjacent node of Linked List.

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

