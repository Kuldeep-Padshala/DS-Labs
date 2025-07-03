#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *link;
};
struct Node *add(struct Node *head){
    while(1){
        printf("enter data or -1 for exit list: ");
        int n = 0;
        scanf("%d",&n);
            if (n == -1)break;
            
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->info=n;
        newnode->link=head;
        head=newnode;
    }
    return head;
}

struct Node* deletedup(struct Node * head){

    struct Node *save=NULL;
    struct Node *save2=NULL;
    
     int temp;
     save=head;

    while(save!=NULL){
        
    save2=head->link;
        
        if (save == NULL)continue;

        while(save2!=NULL){

            if(save->info==save2->link->info){
                
                free(save->link);
            }
            save2=save2->link;
        }
        save=save->link;
    }
    
    return head;
}

struct Node* skipDuplicates(struct Node* head){

    if(head == NULL){
        return head;
    }
    struct Node* curr = head;

    while(curr->link != NULL){

        if(curr->info == curr->link->info){

            struct Node* temp = curr->link;
            curr->link = temp->link;
            free(temp);
            continue;
        }
        else{
            curr = curr->link;
        }
    }
    return head;
}

void print(struct Node *head){

    struct Node *save = head;
    while (save != NULL){
        printf("%d-> ", save->info);
        save = save->link;
    }
}

void main(){

    struct Node *head = NULL;
    int x;
    scanf("%d", &x);
    struct Node *arr[x];

    for (int i = 0; i < x; i++){

        arr[i] = NULL;
        arr[i] = add(arr[i]);
        print(arr[i]);
        printf("\n");
    }

    arr[0] = skipDuplicates(arr[0]);
    print(arr[0]);

}