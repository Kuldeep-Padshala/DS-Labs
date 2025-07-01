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


struct Node* swapKthNode(struct Node* head, struct Node* curr, struct Node* curr2){

     if (curr == curr2) return head;
    struct Node* temp1 = (curr == NULL) ? head : curr->next;
    struct Node* temp2 = (curr2 == NULL) ? head : curr2->next;

    if (temp1 == NULL || temp2 == NULL) return head;

    struct Node* forw1 = temp1->next;
    struct Node* forw2 = temp2->next;

    temp1->next = forw2;
    temp2->next = forw1;

    if (curr != NULL){
        curr->next = temp2;
    }
    else{
        head = temp2;
    }

    if (curr2 != NULL){
        curr2->next = temp1;
    }
    else{
        head = temp1;
    }

    if (temp1 == curr2) {  // temp1 right before temp2
        temp2->next = temp1;
        temp1->next = forw2;
    } else if (temp2 == curr) { // temp2 right before temp1
        temp1->next = temp2;
        temp2->next = forw1;
    } else {
        temp1->next = forw2;
        temp2->next = forw1;
    }
    return head;
}
struct Node* sort(struct Node* head){

    struct Node* curr = head;
    struct Node* i, *j;
    int min;
    struct Node* temp, *jp;
    struct Node* ip = NULL;

    for(i=head ; i->next->next != NULL; i = i->next){

        min = i->next->info;

        for(jp = i,j=i->next ; j->next != NULL; jp = jp->next,j = j->next ){

            if(j->info <= min){
                min = j->info;
                temp = jp;
            }
        }
        if(min< i->info){
            head = swapKthNode(head, ip, temp);
        }
        ip = i;
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
    head = insertAtEnd(head, 7);
    display(head);

    head = sort(head);

    display(head);
}

