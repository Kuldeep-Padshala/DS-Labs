// allocate and de-allocate memory for int, char and float variable at runtime.

#include<stdio.h>
#include<stdlib.h>

void main(){

    int *a = (int *)malloc(2*sizeof(int));
    char *b = (char *)malloc(sizeof(char));
    float *c = (float *)malloc(sizeof(float));

    if(a && b && c) {

        *a = 77;
        *b = 'A';
        *c = 3.14;

        printf("Integer: %d\n", *a);
        printf("Character: %c\n", *b);
        printf("Float: %.2f\n", *c);

        free(a);
        free(b);
        free(c);

    } else {
        printf("Memory allocation failed.\n");
    }
}
