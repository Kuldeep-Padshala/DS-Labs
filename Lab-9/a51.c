// calculate the sum of n numbers using Pointer.

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

    int sum=0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];    //also can use *(arr + i)
    }
    printf("Sum of the elements: %d\n", sum);
    free(arr);

}