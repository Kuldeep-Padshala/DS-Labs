// delete a number from a given location in an array

#include<stdio.h>

int main() {

    int n;

    printf("Enter n: ");
    scanf("%d",&n);

    int arr[n];

    for(int i=0; i<n;i++){
        printf("Enter Arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    int pos;
    printf("Enter position to delete element: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return 1;
    }

    for(int i=pos;i<n-1;i++){
        arr[pos] = arr[i+1];
        pos++;
    }

    printf("New array: ");

        for(int j=0;j<n-1;j++){
            printf("%d ",arr[j]);
        }


    
    return 0;
}