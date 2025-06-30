// separate Linked List into Odd And Even

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtFirst(struct Node *head, int x)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->next = head;

    head = newNode;

    return head;
}

struct Node *insertAtLast(struct Node *head, int x)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    struct Node *curr = head;

    while (curr->next != NULL)
    {

        curr = curr->next;
    }

    curr->next = newNode;

    return head;
}

void display(struct Node *head)
{

    struct Node *curr = head;

    if (curr == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    while (curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void separete(struct Node *head, struct Node *head2, struct Node *head3)
{
    if (head == NULL)
        return;

    struct Node *curr = head;
    struct Node *curr2 = head2;
    struct Node *curr3 = head3;
    int firstEven = 1, firstOdd = 1;

    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {
            if (!firstEven) {
                curr2->next = (struct Node *)malloc(sizeof(struct Node));
                curr2 = curr2->next;
            }
            curr2->data = curr->data;
            curr2->next = NULL;
            firstEven = 0;
        }
        else
        {
            if (!firstOdd) {
                curr3->next = (struct Node *)malloc(sizeof(struct Node));
                curr3 = curr3->next;
            }
            curr3->data = curr->data;
            curr3->next = NULL;
            firstOdd = 0;
        }

        curr = curr->next;
    }
}


void main()
{

    struct Node *h1 = NULL;
    struct Node *h2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *h3 = (struct Node *)malloc(sizeof(struct Node));

    h1 = insertAtFirst(h1, 9);
    h1 = insertAtFirst(h1, 8);
    h1 = insertAtFirst(h1, 8);
    h1 = insertAtFirst(h1, 8);
    h1 = insertAtFirst(h1, 8);
    h1 = insertAtFirst(h1, 7);
    h1 = insertAtFirst(h1, 6);
    h1 = insertAtFirst(h1, 6);

    

    display(h1);

    separete(h1,h2,h3);
    
    display(h2);
    display(h3);
}