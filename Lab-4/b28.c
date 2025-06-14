// delete duplicate numbers from an array

#include<stdio.h>

void deleteElement(int arr[], int n, int pos) {
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

int main() {

    int n;

    printf("Enter n: ");
    scanf("%d",&n);

    int arr[n];

    for(int i=0; i<n;i++){
        printf("Enter Arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){

            if(arr[j] == arr[i]){
                deleteElement(arr, n, j);
                n--;
                j--;
            }
        }
    }
    

    printf("New array: ");

        for(int j=0;j<n;j++){
            printf("%d ",arr[j]);
        }


    
    return 0;
}