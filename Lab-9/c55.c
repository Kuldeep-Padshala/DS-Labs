// define a C structure named Student (roll_no, name, branch and batch_no) and also to access the structure members using Pointer.

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[50];
    char branch[50];
    int batch_no;

};

void main(){

    struct Student *s = (struct Student *)malloc(sizeof(struct Student));
    if(s == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &s->roll_no);
    printf("Enter name: ");
    scanf(" %[^\n]s", s->name);
    printf("Enter branch: ");
    scanf(" %[^\n]s", s->branch);
    printf("Enter batch number: ");
    scanf("%d", &s->batch_no);

    printf("\nStudent Details:\n");
    printf("Roll No: %d\n", s->roll_no);
    printf("Name: %s\n", s->name);
    printf("Branch: %s\n", s->branch);
    printf("Batch No: %d\n", s->batch_no);

    free(s);

}