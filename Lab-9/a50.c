// WAP to get and print the array elements using Pointer.

#include <stdio.h>
#include <stdlib.h>

void main(){

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the elements:\n");

    for(int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
        printf("Element at %d: %d\n", i, *(arr + i));
    }

}