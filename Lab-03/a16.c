// read and display n numbers using an array

#include<stdio.h>

int main() {

    int n;

    printf("Enter n: ");
    scanf("%d",&n);

    int arr[n];

    for(int i=0; i<sizeof(arr)/4;i++){
        printf("Enter Arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    for(int i=0; i<sizeof(arr)/4;i++){
        printf("%d",arr[i]);
    }

    
    return 0;
}