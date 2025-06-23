// WAP to get and print the array elements using Pointer.

#include <stdio.h>
#include <stdlib.h>

void main(){

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));  // here int 
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
        printf("Element at %d: %d\n", i, (arr + i));
    }




    // int n, i;
    
    // printf("Enter the number of elements: ");
    // scanf("%d", &n);
    // //  int *iptr=(int *)malloc(sizeof(int )*n); 
    // // int arr[n];  
    // // int *ptr = arr;  
    // int *ptr;
    // printf("enter elements of array:\n", n);
    // for(i = 0; i < n; i++) {
    //     scanf("%d",(ptr+ i*sizeof(int)));  
    // }
    // printf("array elements are:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d ", *(ptr+ i*sizeof(int)));  
    // } 
    // free(ptr);



    // int n, i;
    
    // printf("Enter the number of elements: ");
    // scanf("%d", &n);
    // int *ptr=(int *)malloc(sizeof(int )); 
    // // int arr[n];  
    // // /int *ptr = arr;
    
    // printf("enter elements of array:\n", n);
    // for(i = 0; i < n; i++) {
    //     scanf("%d",(ptr+ i));  
    // }
    // printf("array elements are:\n");
    // for(i = 0; i < n; i++) {
    //     printf("%d ", *(ptr+ i));  
    // }
    // free(ptr);

}

